#ifndef ENEMY_H
#define ENEMY_H

class Enemy: public: Actor
{
Public:
  Enemy();
  Enemy(SDL_Texture* tileset, int lives, int x, int y, int sX, int sY, int sW, int sH);
  ~Enemy();

  void takeDamage();

Private:

};


#endif
