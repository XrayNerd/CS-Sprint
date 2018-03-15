#include "powerup.h"
#include "sprite.h"

Powerup::Powerup() {}

// Real constructor with a delegating constructor
Powerup::Powerup(SDL_Texture* tileset, Graphics &graphics, Vector2 position, unsigned short id,  bool speed, bool health) :
  Tile(tileset, graphics, position, id)
{
  this->_isSpeed = speed;
  this->_isHealth = health;
  this->_isHidden = false;
}

//Hide the tile
void Powerup::hide()
{
  this->_isHidden = true;
}

//Unhide the tile
void Powerup::unHide()
{
  this->_isHidden = false;
}

//Modified draw function
void Powerup::draw(Graphics &graphics, Vector2 camera)
{
  //If Not hidden draw the tile
  if (!this->_isHidden) {
    Sprite::draw(graphics, camera);
  }
}

bool Powerup::getIsSpeed()
{
  return this->_isSpeed;
}

bool Powerup::getIsHealth()
{
  return this->_isHealth;
}
