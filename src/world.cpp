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
      // Convert string read in from
      // file to into int.
      std::stringstream convert(mapStringArray.at(y*World::width + x));
      convert >> id;
      if (id != 22) {
        // Add tile
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
      } else {
        // Add powerup
        Powerup powerup(this->_tileset,
                        graphics,
                        Vector2(x*8*globals::SPRITE_SCALE,
                                y*12*globals::SPRITE_SCALE),
                        id,
                        true,
                        false);
          this->_powerupList.push_back(powerup);
      }
    }
  }
}

// Deconstructor
World::~World() {}

// Runs through tile list and powerup list
// and calls the draw function
void World::draw(Graphics &graphics, Vector2 camera)
{
  for (Tile t : this->_tileList) {
    t.draw(graphics, camera);
  }
  for (Powerup p : this->_powerupList) {
    p.draw(graphics, camera);
  }
}

void World::update(int elapsedtime) {}


// Returns a shared pointer
// of a tile at coords x, y
std::shared_ptr<Tile> World::getTileAt(unsigned int x, unsigned int y)
{
  int xCoord = (x - (x % 8))/8;
  int yCoord = (y - (y % 12))/12;
  std::shared_ptr<Tile> tempTile = make_shared<Tile>();
  *tempTile = this->_tileList[yCoord * World::width + xCoord];
  return tempTile;
}

// Load tileset so it can
// be passed down to tiles
void World::loadTileset(Graphics &graphics)
{
  this->_tileset = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("sprites/spritesheet.png"));
}

// Checks if param other is colliding with
// tiles in the collision list
// Returns an array of all tiles that are
// colliding.
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

std::vector<Powerup> World::returnPowerupList()
{
  return this->_powerupList;
}
