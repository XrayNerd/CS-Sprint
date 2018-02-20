#include <iostream>
#include "world.h"
#include "graphics.h"
#include "tile.h"
using namespace std;


float timeElapsed = 0;
int currentPos = 0;

World::World()
{
}

World::World(Graphics &graphics)
{
  this->loadTileset(graphics);
  for (int y=0; y<World::height; y++)
  {
    for (int x=0; x<World::width; x++)
    {
      Tile tile(this->_tileset,
                graphics,
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

void World::draw(Graphics &graphics, Vector2 camera)
{
  for (int i = 0; i < this->_tileList.size(); i++)
  {
      this->_tileList[i].draw(graphics, camera);
  }
}

void World::update(int elapsedtime)
{
  
}

Tile& World::getTileAt(unsigned int x, unsigned int y)
{
  int xCoord = (x - (x % 8))/8;
  int yCoord = (y - (y % 12))/12;
  return this->_tileList[yCoord * 40/2 + xCoord];
}

void World::loadTileset(Graphics &graphics)
{
  this->_tileset = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("sprites/spritesheet.png"));
}
/*
void World::populateGrid()
{
  for 
}
*/
