#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>

#include "globals.h"

class Graphics;

/*  Sprite class
*   Holds all information for individual sprites
*/

class Sprite
{
public:
  Sprite();
  Sprite(SDL_Texture* tileset, Graphics &graphics, const std::string &filePath, Vector2 sourcePosition, Vector2 size, Vector2 position);
  virtual ~Sprite();
  virtual void update();
  void draw(Graphics &graphics, Vector2 camera);

  Vector2 getSize();
  Vector2 getPosition();
  bool isColliding(Sprite other);

protected:
  Vector2 _position;
  SDL_Rect _sourceRect;
  SDL_Texture* _tileset;
  Vector2 _size;

};

#endif
