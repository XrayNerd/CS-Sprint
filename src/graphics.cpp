#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"
#include "globals.h"

/*  The Graphics class
*   Holds everything for Graphics
*/

Graphics::Graphics()
{
  SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
  SDL_SetWindowTitle(this->_window, "Test Game");
}

Graphics::~Graphics()
{
  SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath)
{
  if (this->_spriteSheet.first == "")
  {
    this->_spriteSheet = std::make_pair(filePath, IMG_Load(filePath.c_str()));
  }
  return this->_spriteSheet.second;
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
  SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip()
{
  SDL_RenderPresent(this->_renderer);
}

void Graphics::clear()
{
  SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
  return this->_renderer;
}
