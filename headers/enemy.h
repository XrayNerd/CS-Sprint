#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public Actor
{
public:
  Enemy();
  Enemy(SDL_Texture* tileset, int x, int y, int sX, int sY, int sW, int sH);
  ~Enemy();

  void takeDamage();

private:

};


#endif
