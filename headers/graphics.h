#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

// Forward declaring in implementation file
// So it is not included too many times.
struct SDL_Window;
struct SDL_Renderer;

#include <string>


class Graphics
{
public:
  Graphics();
  ~Graphics();

  /*  SDL_Surface* loadImage
  *   Loads in image into the _spriteSheets pair
  */
  SDL_Surface* loadImage(const std::string &filepath);

  /*  void blitSurface
  *   Draws a texture to a certain part of the screen
  */
  void blitSurface(SDL_Texture* soruce, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

  /*  void flip
  *   Renders everything to the screen
  */
  void flip();

  /*  void clear
  *   Clears the screen
  */
  void clear();

  /*  SDL_Renderer* getRenderer
  *   Returns the renderer
  */
  SDL_Renderer* getRenderer() const;

private:
  SDL_Window* _window;
  SDL_Renderer* _renderer;

  std::pair<std::string, SDL_Surface*> _spriteSheet;
};

#endif
