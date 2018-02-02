#ifndef ACTOR_H
#define ACTOR_H

#include "globals.h"

class Graphics;
struct SDL_Texture;

class Actor
{
public:
  Actor();
  Actor(SDL_Texture* tileset, Vector2 position, Vector2 tilesetPosition)
  {
    this->_tileset = tileset;
    this->_position = position;
    this->_tilesetPosition = tilesetPosition;
    this->_size = Vector2(8, 12);
  }
  ~Actor();

  void update(int elapsedTime);

  void draw(Graphics &graphics);

  void kill();

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();

  void setTileset(SDL_Texture* tileset)
  {
    this->_tileset = tileset;
  };

private:
  SDL_Texture* _tileset;
  int speed;
  bool _isDead = false;
  float _timeElapsed;
  Vector2 _tilesetPosition;
  Vector2 _position;
  Vector2 _size;
};


#endif
