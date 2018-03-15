#ifndef POWERUP_H
#define POWERUP_H

#include "globals.h"
#include "tile.h"

class Powerup : public Tile
{
public:
  Powerup();
  Powerup(bool speed, bool health);

  void hide();
  void unHide();

  void draw(Graphics &graphics, Vector2 camera);

  bool getIsSpeed();
  bool getIsHealth();

private:
  bool _isHidden;
  bool _isSpeed;
  bool _isHealth;
};


#endif
