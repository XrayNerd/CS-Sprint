#ifndef ACTOR_H
#define ACTOR_H

#include "globals.h"

class Graphics;
Struct SDL_Texture;

class Actor
{
public:
  Actor();
  Actor(SDL_Texture* tileset, int x, int y, int sX, int sY, int sW, int sH);
  ~Actor();

  void update(int elapsedTime);

  void draw(Graphics &graphics);

  void kill();

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();

private:
  int speed;
  bool _isDead;
  float _timeElapsed;
  int _xPos;
  int _yPos;
  int _sX;
  int _sY;
  int _sW;
  int _sH;
};


#endif
