#ifndef TILE_H
#define TILE_H

#include "globals.h"
#include <map>

class Graphics;
struct SDL_Texture;
struct TileType;

class Tile
{
public:
  Tile();
  Tile(SDL_Texture* tileset, Vector2 position, unsigned short id);

  void update(int elapsedtime);
  void draw(Graphics &graphics);
  void setId(unsigned short id);
protected:
  SDL_Texture* _tileset;
  unsigned short _id;
  Vector2 _position;
  Vector2 _tilesetPosition;
  Vector2 _size = Vector2(8, 12);
  bool isPassable;
  bool isBreakable;
  bool isScorePoint;
  bool isPowerUp;
private:
  Vector2 getTypeSpritePos(unsigned short id);
  std::map<unsigned short, Vector2> _typesList = {
    {0, Vector2(96, 24)},
    {1, Vector2(32, 144)},
    {2, Vector2(24, 132)},
    {3, Vector2(88, 156)},
    {4, Vector2(56, 0)},
    {5, Vector2(0, 144)},
    {6, Vector2(72, 156)},
    {7, Vector2(80, 156)},
    {8, Vector2(120, 132)},
    {9, Vector2(24, 144)},
    {10, Vector2(32, 132)},
    {11, Vector2(8, 144)},
    {12, Vector2(16, 144)},
    {13, Vector2(40, 144)}
    };
  
};

#endif
