#include "powerup.h"
#include "sprite.h"
#include "libsqlite.h"

Powerup::Powerup() {}

// Real constructor with a delegating constructor
Powerup::Powerup(SDL_Texture* tileset, Graphics &graphics, Vector2 position, unsigned short id,  bool speed, bool health) :
  Tile(tileset, graphics, position, id)
{
  this->_isSpeed = speed;
  this->_isHealth = health;
  this->_isHidden = false;
}

//Hide the tile
void Powerup::hide()
{
  this->_isHidden = true;
}

//Unhide the tile
void Powerup::unHide()
{
  this->_isHidden = false;
}

bool Powerup::isHidden()
{
  return this->_isHidden;
}

//Modified draw function
void Powerup::draw(Graphics &graphics, Vector2 camera)
{
  //If Not hidden draw the tile
  if (!this->_isHidden) {
    Sprite::draw(graphics, camera);
  }
}

bool Powerup::getIsSpeed()
{
  return this->_isSpeed;
}

bool Powerup::getIsHealth()
{
  return this->_isHealth;
}

void Powerup::randomize()
{
  sqlite::sqlite _db("highquestions.db");
  auto cur = _db.get_statement();
  cur->set_sql("SELECT * FROM powerups LIMIT (ABS(RANDOM()) % (SELECT COUNT(*) FROM powerups)),1;");
  cur->prepare();
  cur->step();

  this->_isSpeed = (cur->get_int(2)>0 ? true : false);
  this->_isHealth = (cur->get_int(3)>0 ? true : false);
}

