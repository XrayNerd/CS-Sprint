#include "sprite.h"
#include "graphics.h"
#include "globals.h"

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
  this->_sourceRect.w = size.x;
  this->_sourceRect.h = size.y;
 
}

Sprite::~Sprite()
{

}

void Sprite::draw(Graphics &graphics, Vector2 camera)
{
  SDL_Rect destinationRectangle =
    {this->_position.x - camera.x,
     this->_position.y - camera.y,
     this->_sourceRect.w * globals::SPRITE_SCALE,
     this->_sourceRect.h * globals::SPRITE_SCALE};

  graphics.blitSurface(this->_tileset,
		       &this->_sourceRect,
		       &destinationRectangle);
}

Vector2 Sprite::getPosition()
{
  return this->_position;
}
  
void Sprite::update()
{
  
}
