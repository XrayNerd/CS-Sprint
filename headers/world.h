#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <map>

#include "globals.h"
#include "tile.h"

class Graphics;

struct SDL_Texture;
struct SDL_Rect;
struct TileType;


class World
{
public:
  World();
  World(Graphics &graphics);
  ~World();

  void update(int elapsedtime);
  void draw(Graphics &graphics);

  int height;
  int width;

  Tile& getTileAt(unsigned int x, unsigned int y);
  void destroyTileAt(int x, int y);
private:
  SDL_Texture* _tileset;
  std::vector<Tile> _tileList;
  
  void loadTileset(Graphics &graphics);
};

#endif
