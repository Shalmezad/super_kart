#include "inputhandler.h"

bool InputHandler::left = false;
bool InputHandler::right= false;
bool InputHandler::space= false;

bool InputHandler::inputLeft()
{
  return left;
}

bool InputHandler::inputRight()
{
  return right;
}

bool InputHandler::inputThrottle()
{
  return space;
}

void InputHandler::handleEvent(SDL_Event *event)
{
  switch(event->type)
  {
    case SDL_KEYDOWN:
      handleKey(event->key.keysym.sym, true);
      break;
    case SDL_KEYUP:
      handleKey(event->key.keysym.sym, false);
      break;
  }
}

void InputHandler::handleKey(SDLKey key, bool value)
{
      switch(key)
      {
        case SDLK_LEFT:
          left = value;
          break;
        case SDLK_RIGHT:
          right = value;
          break;
        case SDLK_SPACE:
          space = value;
          break;
      }
}


