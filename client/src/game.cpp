#include "game.h"

#include <stdexcept>
#include "shautil.h"
#include "inputhandler.h"
#include <math.h>

Game::Game()
{
  width = 800;
  height = 600;
  fullscreen = false;
}

void Game::setup()
{
  int quit=0;
  SDL_Event event; 
  int x,y;

  Uint32 currentColor;
  
  //if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)
  if(SDL_Init(SDL_INIT_VIDEO)==-1)
  {
    printf("Could not initialize SDL: %s.\n", SDL_GetError());
    throw std::runtime_error("Unable to initialize SDL.");
  }

  if(fullscreen)
  {
    screen = SDL_SetVideoMode(width,height,24,SDL_SWSURFACE | SDL_FULLSCREEN); 
  }
  else
  {
    screen = SDL_SetVideoMode(width,height,24,SDL_HWSURFACE ); 
  }

  if(screen == NULL)
  {
    printf("Unable to set video mode: %s.\n", SDL_GetError());
    throw std::runtime_error("Unable to set video mode.");
  }

  currentColor = SDL_MapRGB(screen->format, 0xff, 0xff, 0x00);
  mode7.texture = loadSurface("assets/map1.png", screen);

  running = true;
}

void Game::teardown()
{
  SDL_Quit();
}

void Game::update()
{
  if(running)
  {
    handleEvents();
    if(InputHandler::inputLeft() && !InputHandler::inputRight())
    {
      mode7.angle -= .1;
    }
    else if(InputHandler::inputRight() && !InputHandler::inputLeft())
    {
      mode7.angle += .1;
    }
    if(InputHandler::inputThrottle())
    {
      mode7.posX += cos(mode7.angle) * 2;
      mode7.posY += sin(mode7.angle) * 2;
    }
    render();
  }
}

void Game::render()
{
    //lock screen
    if(SDL_MUSTLOCK(screen))
    {
      if(SDL_LockSurface(screen)<0)
      {
        printf("Can't lock screen: %s.\n", SDL_GetError());
        
      throw std::runtime_error("Unable to lock screen (required by system).");
      } 
    }

    //draw
    mode7.render(screen);

    //unlock
    if(SDL_MUSTLOCK(screen))
    {
      SDL_UnlockSurface(screen);
    }

    //update rect
    SDL_UpdateRect(screen, 0, 0, width, height);
 
}


void Game::handleEvents()
{
  SDL_Event event;
    //handle events
    while(SDL_PollEvent(&event))
    {
      switch(event.type)
      {
        case SDL_QUIT:
          running = false;
          break;
        case SDL_KEYDOWN:
          InputHandler::handleEvent(&event);
          break;
        case SDL_KEYUP:
          InputHandler::handleEvent(&event);
          break;
                   
      }
    }


}
