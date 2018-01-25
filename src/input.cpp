#include "input.h"

/*  Input class
*   Keeps track of keyboard state
*/

// This function gets called at the beginning of each new frame
// to reset the keys that are no longer relevant
void Input::beginNewFrame()
{
  this->_pressedKeys.clear();
  this->_releasedKeys.clear();
}

// This is called when a key is pressed
void Input::keyDownEvent(const SDL_Event& event)
{
  this->_pressedKeys[event.key.keysym.scancode] = true;
  this->_heldKeys[event.key.keysym.scancode] = true;
}

// This is called when a key is _releasedKeys
void Input::keyUpEvent(const SDL_Event& event)
{
  this->_releasedKeys[event.key.keysym.scancode] = true;
  this->_heldKeys[event.key.keysym.scancode] = false;
}

// Check if a key was pressed during current frame
bool Input::wasKeyPressed(SDL_Scancode key)
{
  return this->_pressedKeys[key];
}

// Check if a key was released during current frame
bool Input::wasKeyReleased(SDL_Scancode key)
{
  return this->_releasedKeys[key];
}

// Check if a key is currently held
bool Input::isKeyHeld(SDL_Scancode key)
{
  return this->_heldKeys[key];
}
