#ifndef TILE_H
#define TILE_H

class World;

class Tile
{
public:
  Tile(World &world, int x, int y);
  ~Tile();

  enum TileType { Empty, Breakable, Unbreakable, StairUp, StairDown };
  TileType type = Empty;
  TileType getTileType();
  void setTileType(TileType &TileType);

  int X;
  int Y;

  int getX()
  {
    return X;
  }
  int getY()
  {
    return Y;
  }

protected:
  void setY(int value)
  {
    Y = value;
  }
  void setX(int value)
  {
    X = value;
  }
};

#endif
