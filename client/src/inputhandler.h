#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_

#include "SDL.h"

class InputHandler
{
  //attributes
  public:

  private:
    static bool left;
    static bool right;
    static bool space;

  //methods
  public:
    static void handleEvent(SDL_Event *event);

    static bool inputLeft();
    static bool inputRight();
    static bool inputThrottle();
  private:
    static void handleKey(SDLKey key, bool value);
 
};

#endif
