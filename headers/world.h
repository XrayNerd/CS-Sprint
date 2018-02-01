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

  Tile GetTileAt(int x, int y);
  void DestroyTileAt(int x, int y);
private:
  SDL_Texture* _tileset;
  std::vector<Tile> _tileList;
  
  void loadTileset(Graphics &graphics);
};

#endif
