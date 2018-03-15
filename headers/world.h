#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <map>
#include <memory>
#include <iostream>

#include "globals.h"
#include "tile.h"
#include "powerup.h"

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
  void draw(Graphics &graphics, Vector2 camera);

  int height = 50;
  int width = 80;

  std::shared_ptr<Tile> getTileAt(unsigned int x, unsigned int y);
  void destroyTileAt(int x, int y);

  std::vector<Sprite> checkTileCollisions(Sprite other);
  std::vector<Powerup> returnPowerupList();

private:
  SDL_Texture* _tileset;
  std::vector<Tile> _tileList;
  std::vector<Powerup> _powerupList;
  std::vector<Tile> _collisionList;
  std::vector< std::vector< std::shared_ptr<Tile> > > _gridList;

  void populateGrid();
  void loadTileset(Graphics &graphics);
};

#endif
