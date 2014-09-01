#ifndef _SHA_UTIL_H_
#define _SHA_UTIL_H_

#include "SDL.h"
#include <string>

void putPixelOnSurface(SDL_Surface *surface, int x, int y, Uint32 pixelColor);
Uint32 getPixelFromSurface(SDL_Surface *surface, int x, int y);

SDL_Surface* loadSurface(std::string path, SDL_Surface *gScreenSurface);

#endif
