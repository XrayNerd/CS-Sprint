#include "tile.h"
#include "graphics.h"
#include "sprite.h"

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

Tile::Tile()
{

}

Tile::Tile(SDL_Texture* tileset, Graphics &graphics, Vector2 position, unsigned short id) :
  Sprite(tileset,
	 graphics,
	 "sprites/spritesheet.png",
	 types::_typesList[id],
	 Vector2(8, 12),
	 position)
{
  //  this->_tileset = tileset;
  this->_id = id;
}

Vector2 Tile::getTypeSpritePos(unsigned short id)
{
  return types::_typesList[id];
}

unsigned short Tile::getId()
{
  return this->_id;
}

std::pair<int, int> Tile::getCoords()
{
  std::pair<int, int> m;
  m.first = this->_position.x;
  m.second = this->_position.y;
  return m;
}


void Tile::update(int elapsedtime)
{
  
}

void Tile::draw(Graphics &graphics, Vector2 camera)
{
  Sprite::draw(graphics, camera);
  /*
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

  graphics.blitSurface(this->_tileset, &sourceRect, &destRect);*/
}
