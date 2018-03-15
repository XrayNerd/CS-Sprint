#ifndef GAME_H
#define GAME_H

#include "sprite.h"
#include "world.h"
#include "player.h"
#include "enemy.h"

class Graphics;

class Game
{
public:
  Game();
  ~Game();
private:
  void gameLoop();
  void draw(Graphics &graphics, Vector2 camera);
  void update(float elapsedTime);
  void loadTileset(Graphics &graphics);

  void setCameraPosition(Vector2 position);

  Vector2 _camera;
  World _world;
  Player _player;
  Enemy _enemy;
  Sprite _sprite;

  int _score;

  SDL_Texture* _tileset;

};

#endif
