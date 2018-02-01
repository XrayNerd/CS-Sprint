#include "tile.h"
#include "graphics.h"

#include <SDL2/SDL.h>

Tile::Tile()
{

}

Tile::Tile(SDL_Texture* tileset, Vector2 position, unsigned short id)
{
  this->_tileset = tileset;
  this->_position = position;
  setId(id);
  this->_size = Vector2(8, 12);
}

Vector2 Tile::getTypeSpritePos(unsigned short id)
{
  return this->_typesList[id];
}

void Tile::setId(unsigned short id)
{
  this->_id = id;
  this->_tilesetPosition = getTypeSpritePos(id);
}



void Tile::update(int elapsedtime)
{
  
}

void Tile::draw(Graphics &graphics)
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
    this->_size.x,
    this->_size.y
  };

  graphics.blitSurface(this->_tileset, &sourceRect, &destRect);
}
