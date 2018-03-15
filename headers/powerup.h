#ifndef POWERUP_H
#define POWERUP_H

#include "globals.h"
#include "tile.h"

class Powerup : public Tile
{
public:
  Powerup();
  Powerup(SDL_Texture* tileset, Graphics &graphics, Vector2 position, unsigned short id, bool speed, bool health);

  void hide();
  void unHide();

  void draw(Graphics &graphics, Vector2 camera);

  bool getIsSpeed();
  bool getIsHealth();

  bool isHidden();

  void randomize();

private:
  bool _isHidden;
  bool _isSpeed;
  bool _isHealth;
};


#endif
