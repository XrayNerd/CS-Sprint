#include <SDL2/SDL.h>

#include "graphics.h"

/*  The Graphics class
*   Holds everything for Graphics
*/

Graphics::Graphics()
{
  SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
  SDL_SetWindowTitle(this->_window, "Test Game");
}

Graphics::~Graphics()
{
  SDL_DestroyWindow(this->_window);
}
