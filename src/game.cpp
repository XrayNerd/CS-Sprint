#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

#include "game.h"
#include "graphics.h"
#include "input.h"

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
  this->gameLoop();
}

Game::~Game()
{

}

void Game::gameLoop()
{
  Graphics graphics;
  Input input;
  SDL_Event event;
  this->_world = World(graphics);
  this->_player = Player(this->_tileset, Vector2(100, 100), Vector2(16,0));

  int LAST_UPDATE_TIME = SDL_GetTicks();
  // Start the game loop
  while (true)
  {
    input.beginNewFrame();

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


    const int CURRENT_TIME_MS = SDL_GetTicks();
    int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
    // This means we cant go above 60 FPS
    this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
    LAST_UPDATE_TIME = CURRENT_TIME_MS;

    this->draw(graphics);
  }
}

void Game::draw(Graphics &graphics)
{
  graphics.clear();

  this->_world.draw(graphics);
  this->_player.draw(graphics, 100, 100);

  graphics.flip();
}

void Game::update(float elapstedtime)
{
  this->_world.update(elapstedtime);
}

void Game::loadTileset(Graphics &graphics)
{
  this->_tileset = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("sprites/spritesheet.png"));
}
