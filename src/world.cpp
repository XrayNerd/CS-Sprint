#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "world.h"
#include "graphics.h"
#include "tile.h"
using namespace std;


float timeElapsed = 0;
int currentPos = 0;

World::World() {}

World::World(Graphics &graphics)
{
  std::ifstream in("maps/MapArray.txt");
  
  // Credits to Indiana Sept 2014
  // cpp.indi.frih.net/blog/2014/09/how-to-read-an-entire-file-into-memory-in-cpp
  auto ss = std::ostringstream{};
  ss << in.rdbuf();
  auto s = ss.str();
  
  std::stringstream streamString(s);

  vector<string> mapStringArray;
  while (streamString.good())
  {
      string subString;
      std::getline( streamString, subString, ',');
      mapStringArray.push_back( subString );
  }
  this->loadTileset(graphics);
  for (int y=0; y<World::height; y++)
  {
    for (int x=0; x<World::width; x++)
    {
      int id;
      std::stringstream convert(mapStringArray.at(y*World::width + x));
      convert >> id;
      Tile tile(this->_tileset,
                graphics,
                Vector2(x*8*globals::SPRITE_SCALE,
                        y*12*globals::SPRITE_SCALE),
                id
                );
      this->_tileList.push_back(tile);
      if (tile.getId() != 0) {
        this->_collisionList.push_back(tile);
      }
    }
  }
  //this->populateGrid();
}

World::~World() {}

void World::draw(Graphics &graphics, Vector2 camera)
{
  for (int i = 0; i < this->_tileList.size(); i++)
  {
      this->_tileList[i].draw(graphics, camera);
  }
}

void World::update(int elapsedtime) {}

std::shared_ptr<Tile> World::getTileAt(unsigned int x, unsigned int y)
{
  int xCoord = (x - (x % 8))/8;
  int yCoord = (y - (y % 12))/12;
  std::shared_ptr<Tile> tempTile = make_shared<Tile>();
  *tempTile = this->_tileList[yCoord * World::width + xCoord];
  return tempTile;
}

void World::loadTileset(Graphics &graphics)
{
  this->_tileset = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("sprites/spritesheet.png"));
}

void World::populateGrid()
{
  // Create a check for collidable tiles only
  //
  for(int i=0;i<World::width/10*World::height/10;i++) {
    vector< std::shared_ptr<Tile> > grid;
      this->_gridList.push_back(grid);
  }
  this->getTileAt((40+8)*16, (30+1)*24);
  for (int y=0; y<World::height; y += 10) {
    for (int x=0; x<World::width; x += 10) {
      for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
          this->_gridList[(y/10)*(World::width/10)
                          + x/10].push_back(this->getTileAt((y+i)*16, (x+j)*24));
        }
      }
    }
  }
}


std::vector<Sprite> World::checkTileCollisions(Sprite other)
{
  std::vector<Sprite> others;
  for (x : this->_collisionList) {
    if (x.isColliding(other)) {
      others.push_back(x);
    }
  }
  return others;
}
