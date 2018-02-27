#include "actor.h"
#include "graphics.h"


Actor::Actor()
{
  
}

Actor::Actor(SDL_Texture* tileset, Graphics &graphics, Vector2 position, Vector2 tilesetPosition, Vector2 size) :
  Sprite(tileset,
	 graphics,
	 "sprites/spritesheet.png",
	 tilesetPosition,
	 size,
	 position)
{}

Actor::~Actor()
{

}

void Actor::draw(Graphics &graphics, Vector2 camera)
{
   SDL_Rect destinationRectangle =
     {_position.x - camera.x,
      _position.y - camera.y,
      _size.x,
      _size.y};
   SDL_Rect fillRectangle =
     {_position.x - camera.x,
      _position.y - camera.y + 8,
      _size.x,
      _size.y - _size.y/4};
  SDL_SetRenderDrawColor(graphics.getRenderer(), 0x00, 0x00, 0x00, 0xFF );
  SDL_RenderFillRect(graphics.getRenderer(), &fillRectangle);
  graphics.blitSurface(_tileset,
		       &_sourceRect,
		       &destinationRectangle);
}
// Sprite::draw(graphics, camera);
  /*
  SDL_Rect destRect =
  {
    Sprite::_position.x,
    Sprite::_position.y,
    this->_size.x * globals::SPRITE_SCALE,
    this->_size.y * globals::SPRITE_SCALE
  };

  SDL_Rect sourceRect =
  {
    this->_tilesetPosition.x,
    this->_tilesetPosition.y,
    8,
    12
    };

    graphics.blitSurface(this->_tileset, &sourceRect, &destRect);*/
//}

void Actor::update(int elapsedTime)
{
  this->_position.x += this->_deltaPosition.x * elapsedTime/5;
    this->_position.y += this->_deltaPosition.y * elapsedTime/5;
}

/* This is y-- because the coordinate
 * system starts in the top left.
 */

void Actor::moveUp()
{
  this->_deltaPosition.y = -1;
}

void Actor::moveDown()
{
  this->_deltaPosition.y = 1;
}

void Actor::moveLeft()
{
  this->_deltaPosition.x = -1;
}

void Actor::moveRight()
{
  this->_deltaPosition.x = 1;
}

void Actor::stopMovingX()
{
  this->_deltaPosition.x = 0.0f;
}
void Actor::stopMovingY()
{
  this->_deltaPosition.y = 0.0f;
}

void Actor::kill()
{

}

void Actor::loadTileset(Graphics &graphics)
{
  this->_tileset = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("sprites/spritesheet.png"));
}

