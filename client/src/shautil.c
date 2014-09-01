#include "shautil.h"

#include "SDL_image.h"

#include <math.h>

void putPixelOnSurface(SDL_Surface *surface, int x, int y, Uint32 pixelColor)
{
  //cap x/y
  if(x < 0)
  {
    x = x % 8;
    if(x < 0) x *= -1;
  }
  if (y < 0)
  {
    y = y % 8;
    if(y < 0) y *= -1;  
  }
  if (x > surface->w - 1)
  {
    x = x % 8 + surface->w - 1;
  }
  if (y > surface->h - 1)
  {
    y = y % 8 + surface->h - 1;
  }

  x = std::max(x,0);
  x = std::min(x, surface->w - 1);
  y = std::max(y,0);
  y = std::min(y, surface->h - 1);
  //Uint32 *pixels = (Uint32 *)surface->pixels;
  //pixels[(y*surface->w) + x] = pixelColor;
  int bpp = surface->format->BytesPerPixel;
  Uint8 *p = (Uint8 *)surface->pixels + y * surface -> pitch + x * bpp;
  switch(bpp)
  {
    case 1:
      *p = pixelColor;
      break;
    case 2:
      *(Uint16 *)p = pixelColor;
      break;
    case 3:
      if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
      {
        p[0] = (pixelColor >> 16) & 0xff;
        p[1] = (pixelColor >> 8) & 0xff;
        p[2] = (pixelColor) & 0xff;
      }
      else
      {
        p[0] = (pixelColor) & 0xff;
        p[1] = (pixelColor >> 8) & 0xff;
        p[2] = (pixelColor >> 16) & 0xff;
      }
      break;
    case 4:
      *(Uint32*)p = pixelColor;
      break; 
  }
}

Uint32 getPixelFromSurface(SDL_Surface *surface, int x, int y)
{

  if(x < 0)
  {
    x = x % 8;
    if(x < 0) x *= -1;
  }
  if (y < 0)
  {
    y = y % 8;
    if(y < 0) y *= -1;  
  }
  if (x > surface->w - 1)
  {
    x = x % 8 + surface->w - 9;
  }
  if (y > surface->h - 1)
  {
    y = y % 8 + surface->h - 9;
  }



  //cap x/y
  x = std::max(x,0);
  x = std::min(x, surface->w - 1);
  y = std::max(y,0);
  y = std::min(y, surface->h - 1);
  //Uint32 *pixels = (Uint32 *)surface->pixels;
  //return pixels[(y * surface->w) + x];
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

SDL_Surface* loadSurface(std::string path, SDL_Surface *gScreenSurface)
{
   //The final optimized image 
  SDL_Surface* optimizedSurface = NULL; 
  //Load image at specified path 
  SDL_Surface* loadedSurface = IMG_Load( path.c_str() ); 
  if( loadedSurface == NULL ) 
  { 
    printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() ); 
  }
  else 
  { 
    //Convert surface to screen format 
    optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0); 
    if( optimizedSurface == NULL ) 
    { 
      printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() ); 
    } 
    //Get rid of old loaded surface 
    SDL_FreeSurface( loadedSurface ); 
  } 
  return optimizedSurface;
}
