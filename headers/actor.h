#ifndef ACTOR_H
#define ACTOR_H

#include "globals.h"

class Graphics;
struct SDL_Texture;

class Actor
{
public:
  Actor();
  Actor(Graphics &graphics, Vector2 position, Vector2 tilesetPosition);
  
  ~Actor();

  void update(int elapsedTime);

  void draw(Graphics &graphics);

  void kill();

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
  void stopMovingX();
  void stopMovingY();

  void loadTileset(Graphics &graphics);

private:
  SDL_Texture* _tileset;
  int speed;
  bool _isDead = false;
  float _timeElapsed;
  Vector2 _deltaPosition;
  Vector2 _tilesetPosition;
  Vector2 _position;
  Vector2 _size;
};


#endif
