#include "actor.h"
#include "enemy.h"


Enemy::Enemy() {}

Enemy::Enemy(SDL_Texture* tileset, Graphics &graphics, Vector2 position, Vector2 tilesetPosition, float size )
  : Actor(tileset, graphics, position, tilesetPosition)
{
  this->_size = size;
}

Enemy::~Enemy() {}

void Enemy::draw(Graphics &graphics, Vector2 camera)
{
  SDL_Rect destinationRectangle =
    {_position.x - camera.x,
     _position.y - camera.y,
     _sourceRect.w * 2 * globals::SPRITE_SCALE * this->_size,
     _sourceRect.h * 2 * globals::SPRITE_SCALE * this->_size};
  SDL_Rect fillRectangle =
     {_position.x - camera.x,
      _position.y - camera.y + 8 * globals::SPRITE_SCALE,
      _sourceRect.w * 2 * globals::SPRITE_SCALE * this->_size,
      _sourceRect.h * 2 * globals::SPRITE_SCALE * this->_size-(8*globals::SPRITE_SCALE*this->_size)};
  SDL_SetRenderDrawColor(graphics.getRenderer(), 0x00, 0x00, 0x00, 0xFF );
  SDL_RenderFillRect(graphics.getRenderer(), &fillRectangle);
  graphics.blitSurface(_tileset,
		       &_sourceRect,
		       &destinationRectangle);

}

void Enemy::takeDamage()
{
  this->_size -= 0.25;
}


void Enemy::moveUp()
{
  _deltaPosition.y = -12;
}

void Enemy::moveDown()
{
  _deltaPosition.y = 12;
}

void Enemy::moveLeft()
{
  _deltaPosition.x = -8;
}

void Enemy::moveRight()
{
  _deltaPosition.x = 8;
}

void Enemy::stopMovingX()
{
  _deltaPosition.x = 0.0f;
}
void Enemy::stopMovingY()
{

  _deltaPosition.y = 0.0f;
}

void Enemy::update(int elapsedTime)
{
  this->_totalElapsedTime += elapsedTime;
  if (this->_totalElapsedTime > 1000)
  {
    _totalElapsedTime -= 1000;
    _position.x += this->_deltaPosition.x*2;
    _position.y += this->_deltaPosition.y*2;
  }
}
