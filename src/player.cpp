#include "player.h"
#include "graphics.h"

Player::Player() {

}

Player::Player(Graphics &graphics, int lives, Vector2 position, Vector2 tilesetPosition)
  : Actor(graphics, position, tilesetPosition)
{
  this->_lives = lives;
  this->_collectedNotes = 0;
}

Player::~Player() {}

void Player::draw(Graphics &graphics)
{
  Actor::draw(graphics);
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


