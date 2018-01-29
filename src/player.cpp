#include "actor.h"
#include "player.h"

Player::Player() {}

Player::Player(SDL_Texture* tileset, int lives, int x, int y, int sX, int sY, int sW, int sH)
{
  this->_tileset = tilset;
  this->_lives = lives;
  this->_xPos = x;
  this->_yPos = y;
  this->_sX = sX;
  this->_sY = sY;
  this->_sW = sW;
  this->_sH = sH;
  this->_isDead = false;
  this->_collectedNotes = 0;
}

Player::~Player() {}

Actor::update(int elapstedTime)
{

}

Actor::draw(Graphics &graphics)
{

}

Actor::moveUp()
{

}

Actor::moveDown()
{

}

Actor::moveLeft()
{

}

Actor::moveRight()
{

}

Actor::kill()
{

}

Player::takeDamage()
{
  if (lives > 0)
  {
    this->_lives--;
  }
  else
  {
    this->kill();
  }
}

Player::collectNote()
{
  this->_collectedNotes++;
}
