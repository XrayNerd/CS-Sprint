#include "powerup.h"

Powerup::Powerup() {}

// Real constructor
Powerup::Powerup(bool speed, bool health)
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
  } else {

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
