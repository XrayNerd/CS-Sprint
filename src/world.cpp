#include <iostream>
#include "world.h"
#include "graphics.h"
#include "tile.h"

using namespace std;

World::World()
{
}

World::World(Graphics &graphics)
{
  this->loadTileset(graphics);
  for (int x=0; x<75/globals::SPRITE_SCALE; x++)
  {
    for (int y=0; y<40/globals::SPRITE_SCALE; y++)
    {
      Tile tile(this->_tileset,
		Vector2(x*8*globals::SPRITE_SCALE,
			y*12*globals::SPRITE_SCALE),
		0
	    );
      this->_tileList.push_back(tile); 
    }
  }

}
World::~World()
{

}

void World::draw(Graphics &graphics)
{
  for (int i = 0; i < this->_tileList.size(); i++)
  {
    this->_tileList[i].draw(graphics);
  }
}

void World::update(int elapsedtime)
{
  for (int i = 0; i < this->_tileList.size(); i++)
  {
    this->_tileList[i].update(elapsedtime);
  }
}

void World::loadTileset(Graphics &graphics)
{
  this->_tileset = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("sprites/spritesheet.png"));
}
