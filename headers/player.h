#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"

class Player : public Actor
{
public:
  Player();
  Player(Graphics &graphics, int lives, Vector2 position, Vector2 tilesetPosition);
  ~Player();

  void draw(Graphics &graphics);
  
  void takeDamage();
  void collectNote();
protected:
  int _collectedNotes;
  int _lives;
  Vector2 _position;
  Vector2 _tilesetPosition;
  Vector2 _size;
};


#endif
