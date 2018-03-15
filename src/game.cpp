#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <random>

#include "game.h"
#include "graphics.h"
#include "input.h"
#include "highscore.h"

/*  Game class
*   Computes the *main* game loop and everything required for that
*/

namespace
{
  const int FPS = 60;
  const int MAX_FRAME_TIME = 6 * 1000 / FPS;
}

Game::Game()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  this->_score = 0;

  this->gameLoop();
}

Game::~Game()
{
  std::cout<<"SCORE: " << this->_score <<std::endl;
  std::cout<<"Enter your name: ";
  std::string name;
  std::getline(std::cin, name);

  Highscore highscore(name, this->_score);
  highscore.addToHighscoreList();

  for (Highscore h : highscore.getHighscores()) {
    std::cout<<h.getName()<<": "<<h.getScore()<<std::endl;
  }
}

void Game::gameLoop()
{
  Graphics graphics;
  Input input;
  SDL_Event event;
  this->loadTileset(graphics);
  this->_world = World(graphics);
  this->_enemy = Enemy(_tileset, graphics, Vector2(200,200), Vector2(8,0), 3);
  this->_player = Player(_tileset, graphics, 3, Vector2(300, 240), Vector2(16,0));
  this->_sprite = Sprite(_tileset, graphics, "sprites/spritesheet.png", Vector2(56, 0), Vector2(8, 12), this->_player.getPosition());


  // TODO: Check on multi core
  //
  int LAST_UPDATE_TIME = SDL_GetTicks();
  // Start the game loop
  while (true)
  {
     input.beginNewFrame();
     this->_enemy.pathfinding(this->_player);

    if (SDL_PollEvent(&event))
    {
      if (event.type == SDL_KEYDOWN)
      {
        // Check for a single key press
        if (event.key.repeat == 0)
        {
          input.keyDownEvent(event);
        }

      }
      else if (event.type == SDL_KEYUP)
      {
        input.keyUpEvent(event);
      }
      else if (event.type == SDL_QUIT)
      {
        return;
      }
    }
    if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
    {
      return;
    }
    if (input.isKeyHeld(SDL_SCANCODE_A) == true)
    {
      this->_player.moveLeft();
    }
    if (input.isKeyHeld(SDL_SCANCODE_D) == true)
    {
      this->_player.moveRight();
    }
    if (input.isKeyHeld(SDL_SCANCODE_W) == true)
    {
      this->_player.moveUp();
    }
    if (input.isKeyHeld(SDL_SCANCODE_S) == true)
    {
      this->_player.moveDown();
    }
    if ((!input.isKeyHeld(SDL_SCANCODE_W) &&
	 !input.isKeyHeld(SDL_SCANCODE_S)) ||
	(input.isKeyHeld(SDL_SCANCODE_W) &&
	 input.isKeyHeld(SDL_SCANCODE_S)))
    {
      this->_player.stopMovingY();
    }
    if ((!input.isKeyHeld(SDL_SCANCODE_A) &&
	 !input.isKeyHeld(SDL_SCANCODE_D)) ||
	(input.isKeyHeld(SDL_SCANCODE_A) &&
	 input.isKeyHeld(SDL_SCANCODE_D)))
    {
      this->_player.stopMovingX();
    }


    const int CURRENT_TIME_MS = SDL_GetTicks();
    int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
    this->_score += CURRENT_TIME_MS;
    // This means we cant go above 60 FPS
    this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
    LAST_UPDATE_TIME = CURRENT_TIME_MS;

  this->draw(graphics, this->_camera);
  }
}

void Game::draw(Graphics &graphics, Vector2 camera)
{
  graphics.clear();
  this->_world.draw(graphics, camera);
  this->_player.draw(graphics, camera);
  this->_sprite.draw(graphics, camera);
  this->_enemy.draw(graphics, camera);
  graphics.flip();
}

void Game::update(float elapsedTime)
{
  Vector2 playerPos = this->_player.getPosition();
  
  this->_world.update(elapsedTime);
  this->_player.update(elapsedTime);
  this->_enemy.Enemy::update(elapsedTime);
  this->setCameraPosition(Vector2((this->_player.getPosition().x + 8) - globals::SCREEN_WIDTH/2,
				    (this->_player.getPosition().y + 16) - globals::SCREEN_HEIGHT/2));

  
  // Check collisions
  // Tile
  std::vector<Sprite> others;
  others = this->_world.checkTileCollisions(this->_player);
  if (others.size() > 0) {
    this->_player.setPosition(playerPos);
  }

  // Powerups
  for( Powerup p : this->_world.getPowerupList()) {
    if (this->_player.isColliding(p) && !p.isHidden()) {
      if (p.getIsSpeed()) {
        this->_player.incSpeed();
      }
      if (p.getIsHealth()){
        this->_player.incHealth();
      }
    }
    p.randomize();
    p.hide();
  }

  // Questions
  for ( Question q : this->_world.getQuestionTileList()) {
    if (this->_player.isColliding(q)) {
      std::vector<std::string> stringArr = q.getRandomQuestion();
      
      std::cout<<stringArr[0]<<std::endl;
      int randQ = std::rand() % 2;
      if (randQ == 0) {
        std::cout<<"1: "<<stringArr[1]<<std::endl;
        std::cout<<"2: "<<stringArr[2]<<std::endl;
      } else {
        std::cout<<"1: "<<stringArr[2]<<std::endl;
        std::cout<<"2: "<<stringArr[1]<<std::endl;
      }
      int  answer;
      std::cout << "What is the correct answer 1 or 2? : ";
      std::cin >> answer;
      if (randQ == 0) {
        if (answer == 1) {
          std::cout<<"Correct!"<<std::endl;
          this->_score += 1000000;
        } else {
          std::cout<<"Incorrect answer!"<<std::endl;
          this->_player.takeDamage();
          this->_score -= 1000000;
        }
      } else {
        if (answer == 2) {
          std::cout<<"Correct!"<<std::endl;
          this->_score += 1000000;
        } else {
          std::cout<<"Incorrect answer!"<<std::endl;
          this->_player.takeDamage();
          this->_score -= 1000000;
        }
      }
      this->_player.setPosition(playerPos);
    }
  }
}

void Game::loadTileset(Graphics &graphics)
{
  this->_tileset = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("sprites/spritesheet.png"));
}

void Game::setCameraPosition(Vector2 position)
{
  this->_camera = position;
}
