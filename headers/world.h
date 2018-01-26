#ifndef WORLD_H
#define WORLD_H

class Tile;

class World
{
public:
  World();
  ~World();

  int height;
  int width;

  Tile GetTileAt(int x, int y);
  void DestroyTileAt(int x, int y);
private:

};

#endif
