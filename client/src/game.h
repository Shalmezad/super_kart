#ifndef _GAME_H_
#define _GAME_H_

#include "SDL.h"
#include "mode7.h"

class Game
{

//Attributes
public:
  bool running;
  
private:
  SDL_Surface *screen;
  SDL_Surface *texture;
  int width, height;
  bool fullscreen;
  Mode7 mode7;
  bool leftDown, rightDown;

//Methods
public:
  Game();
  void setup();
  void teardown();
  void update();
  
private:
  void render();
  void handleEvents();

};

#endif
