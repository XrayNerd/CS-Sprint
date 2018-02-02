#include "actor.h"
#include "player.h"
#include "graphics.h"

Player::Player() {

}

Player::Player(SDL_Texture* tileset, int lives, Vector2 position, Vector2 tilesetPosition)
{
  Actor::Actor(tileset, position, tilesetPosition);
  this->_lives = lives;
  this->_collectedNotes = 0;
}

Player::~Player() {}



void Actor::moveUp()
{
this->_position.y++;
}

void Actor::moveDown()
{
this->_position.y--;
}

void Actor::moveLeft()
{
this->_position.x--;
}

void Actor::moveRight()
{
this->_position.x++;
}

void Actor::kill()
{

}

void Player::takeDamage()
{
  if (this->_lives > 0)
  {
    this->_lives--;
  }
  else
  {
    this->kill();
  }
}

void Player::collectNote()
{
  this->_collectedNotes += 1;
}

void Actor::update(int elapstedTime)
{

}

void Actor::draw(Graphics &graphics)
{
  SDL_Rect destRect =
  {
    this->_position.x,
    this->_position.y,
    this->_size.x * globals::SPRITE_SCALE,
    this->_size.y * globals::SPRITE_SCALE
  };

  SDL_Rect sourceRect =
  {
    this->_tilesetPosition.x,
    this->_tilesetPosition.y,
    this->_size.x * globals::SPRITE_SCALE,
    this->_size.y * globals::SPRITE_SCALE
  };

  graphics.blitSurface(this->_tileset, &sourceRect, &destRect);
}
