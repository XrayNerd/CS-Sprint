#ifndef PLAYER_H
#define PLAYER_H

class Player: public: Actor
{
Public:
  Player();
  Player(SDL_Texture* tileset, int lives, int x, int y, int sX, int sY, int sW, int sH);
  ~Player();

  void takeDamage();
  void collectNote();
Private:
  int _collectedNotes;
  int _lives;
};


#endif
