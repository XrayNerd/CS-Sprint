#include "player.h"
#include "graphics.h"

Player::Player() {

}

Player::Player(SDL_Texture* tileset, Graphics &graphics, int lives, Vector2 position, Vector2 tilesetPosition)
  : Actor(tileset, graphics, position, tilesetPosition, Vector2(8, 12))
{
  this->_lives = lives;
  this->_collectedNotes = 0;
}

Player::~Player() {}

void Player::draw(Graphics &graphics, Vector2 camera)
{
  Actor::draw(graphics, camera);
}


void Player::takeDamage()
{
  if (this->_lives > 0)
  {
    this->_lives--;
  }
  else
  {
    Actor::kill();
  }
}

void Player::collectNote()
{
  this->_collectedNotes += 1;
}
