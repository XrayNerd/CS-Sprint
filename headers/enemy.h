#ifndef ENEMY_H
#define ENEMY_H

#include "graphics.h"

class Enemy : public Actor
{
public:
  Enemy();
  Enemy(SDL_Texture* tileset, Graphics &graphics, Vector2 position, Vector2 tilesetPosition, float size );
  ~Enemy();

  void draw(Graphics &graphics, Vector2 camera);
  void update(int elapsedTime);

  void takeDamage();

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
  void stopMovingX();
  void stopMovingY();

private:
  float _size;
  float _totalElapsedTime;

};


#endif
