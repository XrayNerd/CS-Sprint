#include "tile.h"
#include "world.h"

namespace
{
  World world;
}

Tile::Tile(World &world, int x, int y)
{
  world = world;
  this->X = x;
  this->Y = y;
}

Tile::~Tile()
{

}
