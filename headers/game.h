#ifndef GAME_H
#define GAME_H

#include "sprite.h"
#include "world.h"
#include "player.h"

class Graphics;

class Game
{
public:
  Game();
  ~Game();
private:
  void gameLoop();
  void draw(Graphics &graphics);
  void update(float elapsedTime);

  World _world;
  Player _player;

};

#endif
