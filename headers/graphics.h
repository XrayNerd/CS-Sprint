#ifndef GRAPHICS_H
#define GRAPHICS_H


// Forward declaring in implementation file
// So it is not included too many times.
struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
public:
  Graphics();
  ~Graphics();
private:
  SDL_Window* _window;
  SDL_Renderer* _renderer;
};

#endif
