#include "mode7.h"

#include "shautil.h"
#include <math.h>

Mode7::Mode7()
{
  horizon = -100;
  fov = 100;
  scale = 200;
  posX = 100;
  posY = 200;
  angle = 3.14159/2;
  height = 30;
}


void Mode7::render(SDL_Surface *screen)
{
    Uint32 currentColor;
    for(int screen_y = -1 * horizon; screen_y < screen->h; screen_y++)
    {
      if(screen_y + horizon != 0)
      {
        float distance = height * scale / (screen_y + horizon);
        float horizontal_scale = distance / scale;
        float line_dx = -1 * sin(angle) * horizontal_scale;
        float line_dy = cos(angle) * horizontal_scale;
        float space_x = posX + (distance * cos(angle)) - (texture ->w / 2 * line_dx);
        float space_y = posY + (distance * sin(angle)) - (texture->w /2  * line_dy);
        for(int screen_x = 0; screen_x < texture->w; screen_x++)
        {
          currentColor = getPixelFromSurface(texture, space_x, space_y);
          putPixelOnSurface(screen, screen_x, screen_y, currentColor);
          space_x += line_dx;
          space_y += line_dy;
        }
      }
    }

}
