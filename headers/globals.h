#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>

namespace globals
{
  const int SCREEN_WIDTH = 600;
  const int SCREEN_HEIGHT = 480;

  const float SPRITE_SCALE = 2.0f;
}

struct Vector2 {
  int x, y;
Vector2(int x, int y) :
  x(x), y(y)
  {}
Vector2() :
  x(0), y(0)
  {}
};

namespace types
{
  static std::vector<Vector2> _typesList = {
    Vector2(96, 24),
    Vector2(32, 144),
    Vector2(24, 132),
    Vector2(88, 156),
    Vector2(56, 0),
    Vector2(0, 144),
    Vector2(72, 156),
    Vector2(80, 156),
    Vector2(120, 132),
    Vector2(24, 144),
    Vector2(32, 132),
    Vector2(8, 144),
    Vector2(16, 144),
    Vector2(40, 144),
    Vector2(0, 132)
  };
}
#endif
