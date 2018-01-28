#include "tile.h"
#include "graphics.h"

#include <math.h>
#include <SDL2/SDL.h>

Tile::Tile()
{

}

Tile::Tile(SDL_Texture* tileset, int x, int y, TileType type, int sX, int sY, int sW, int sH)
{
  this->_tileset = tileset;
  this->_xPos = x;
  this->_yPos = y;
  this->_type = type;
  this->_sX = sX;
  this->_sY = sY;
  this->_sW = sW;
  this->_sH = sH;
  this->_id++;
}

void Tile::update(int elapsedtime)
{
  _timeElapsed += elapsedtime;
  if (_timeElapsed > 25)
  {
    _timeElapsed -= 25;
  }
}

void Tile::draw(Graphics &graphics)
{
  SDL_Rect destRect = 
  { 
    this->_xPos,
    this->_yPos,
    this->_sW * globals::SPRITE_SCALE,
    this->_sH * globals::SPRITE_SCALE
  };

  SDL_Rect sourceRect = 
  { 
    this->_sX,
    this->_sY,
    this->_sW,
    this->_sH
  };

  graphics.blitSurface(this->_tileset, &sourceRect, &destRect);
}


