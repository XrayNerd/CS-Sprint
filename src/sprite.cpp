#include "sprite.h"
#include "graphics.h"
#include "globals.h"
#include <iostream>

Sprite::Sprite() {}

Sprite::Sprite(SDL_Texture* tileset,
	       Graphics &graphics,
	       const std::string &filePath,
	       Vector2 sourcePosition,
	       Vector2 size,
	       Vector2 position)
{
  this->_tileset = tileset;
  this->_position = position;
  this->_sourceRect.x = sourcePosition.x;
  this->_sourceRect.y = sourcePosition.y;
  this->_sourceRect.w = 8;
  this->_sourceRect.h = 12;
  this->_size = size;
  this->_size.x *= globals::SPRITE_SCALE;
  this->_size.y *= globals::SPRITE_SCALE;
}

Sprite::~Sprite()
{

}

void Sprite::draw(Graphics &graphics, Vector2 camera)
{
  SDL_Rect destinationRectangle =
    {this->_position.x - camera.x,
     this->_position.y - camera.y,
     this->_size.x,
     this->_size.y};

  graphics.blitSurface(this->_tileset,
		       &this->_sourceRect,
		       &destinationRectangle);
}

bool Sprite::isColliding(Sprite other)
{
  // self.left
  // Check self.y < other.size.h + other.y
  bool left = this->_position.x > other.getPosition().x + other.getSize().x;
  std::cout<<
    this->_position.x << " > " << other.getPosition().x + other.getSize().x <<std::endl;
  // self.top
  // Check self.x > other.size.w + other.x
  bool top = this->_position.y > other.getPosition().y + other.getSize().y;
  // self.bottom
  // Check self.size.h self.y > other.y
  bool bottom = this->_position.y + this->_size.y < other.getPosition().y;
  // self.right
  // Check self.size.w self.x < other.x
  bool right = this->_position.x + this->_size.x < other.getPosition().x;
  
  return !(left || top || bottom || right);
}

Vector2 Sprite::getPosition()
{
  return this->_position;
}

Vector2 Sprite::getSize()
{
  return this->_size;
}

void Sprite::update()
{

}
