#ifndef TILE_H
#define TILE_H

#include "globals.h"
#include "sprite.h"
#include <map>
#include <vector>

class Graphics;
struct SDL_Texture;
struct TileType;

class Tile : public Sprite
{
public:
  Tile();
  Tile(SDL_Texture* tileset, Graphics &graphics, Vector2 position, unsigned short id);

  void update(int elapsedtime);
  void draw(Graphics &graphics, Vector2 camera);
  unsigned short getId();
  std::pair<int, int> getCoords();
  void getIsPassble();
protected:
  unsigned short _id;
  bool isPassable;
  bool isBreakable;
  bool isScorePoint;
  bool isPowerUp;
private:
  Vector2 getTypeSpritePos(unsigned short id);
  SDL_Texture* _tileset;
  
};

#endif
