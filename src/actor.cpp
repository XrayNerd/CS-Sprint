#include "actor.h"
#include "graphics.h"
#include <iostream>

Actor::Actor()
{
  
}

Actor::Actor(SDL_Texture* tileset,
             Graphics &graphics,
             Vector2 position,
             Vector2 tilesetPosition,
             Vector2 size) :
  Sprite(tileset,
	 graphics,
	 "sprites/spritesheet.png",
	 tilesetPosition,
	 size,
	 position)
{
  this->_speed = 1;
}

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
  this->_deltaPosition.y = -1*this->_speed;
}

void Actor::moveDown()
{
  this->_deltaPosition.y = 1*this->_speed;
}

void Actor::moveLeft()
{
  this->_deltaPosition.x = -1*this->_speed;
}

void Actor::moveRight()
{
  this->_deltaPosition.x = 1*this->_speed;
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

void Actor::setPosition(Vector2 newPosition) {
  this->_position = newPosition;
}

// Handles the collisions with *all*
// tiles the actor is touching.
void Actor::handleCollisionTile(std::vector<Sprite> &others)
{
  for (int i = 0; i < others.size(); i++) {
    int side = Sprite::getCollidingSide(others.at(i));
    if (side != 0) {
      switch(side) {
        //Left
      case 1: {
        std::cout<<"Colliding left"<<std::endl;
        this->_position.x -= this->_deltaPosition.x;
        this->_deltaPosition.x = 0;
        break;
      }
        //Top
      case 10: {
        std::cout<<"Colliding top"<<std::endl;
        this->_position.y -= this->_deltaPosition.y;
        this->_deltaPosition.y = 0;
        break;
      }
        //Bottom
      case 11: {
        std::cout<<"Colliding bottom"<<std::endl;
        this->_position.y -= this->_deltaPosition.y;
        this->_deltaPosition.y = 0;
        break;
      }
        //Right
      case 100: {
        std::cout<<"Colliding Right"<<std::endl;
        this->_position.x -= this->_deltaPosition.x;
        this->_deltaPosition.x = 0;
        break;

      }
      }
    }
  }
}
