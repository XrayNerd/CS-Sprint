#ifndef ACTOR_H
#define ACTOR_H

#include "globals.h"
#include "actor.h"
#include "sprite.h"

class Graphics;
struct SDL_Texture;

class Actor : public Sprite
{
public:
  Actor();
  Actor(SDL_Texture* tileset, Graphics &graphics, Vector2 position, Vector2 tilesetPosition);
  
  ~Actor();

  void update(int elapsedTime);

  void draw(Graphics &graphics, Vector2 camera);

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
};


#endif
