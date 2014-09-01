#ifndef _MODE7_H_
#define _MODE7_H_

#include "SDL.h"

class Mode7
{
  //Attributes
public:
  SDL_Surface* texture;
  float posX, posY;
  float angle; 
  float height;
  
private:
  int horizon;
  int fov;
  int scale;


  //Methods
public:
  Mode7();
  void render(SDL_Surface *screen);
      
};

#endif
