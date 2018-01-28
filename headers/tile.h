#ifndef TILE_H
#define TILE_H

#include "globals.h"

class Graphics;
struct SDL_Texture;
struct TileType;

class Tile
{
public:
  enum TileType { Empty, Breakable, Unbreakable, StairUp, StairDown, Score, Power};


  Tile();
  Tile(SDL_Texture* tileset, int x, int y, TileType type, int sX, int sY, int sW, int sH);

  void update(int elapsedtime);

  void draw(Graphics &graphics);
protected:
  TileType _type = Empty;
  float _timeElapsed;

  SDL_Texture* _tileset;
  int _id;
  int _xPos;
  int _yPos;
  int _sX;
  int _sY;
  int _sW;
  int _sH;


};

#endif
