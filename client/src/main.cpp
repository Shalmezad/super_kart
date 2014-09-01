#include "shautil.h"
#include "game.h"

#include "SDL.h"
#include <stdio.h>

const int GAME_WIDTH = 800;
const int GAME_HEIGHT = 600;

const int RC_SUCCESS = 0;
const int RC_SDL_SETUP_ERROR = -1; const int RC_SDL_RUNTIME_ERROR = -2; 

int main(int argc, char * argv[])
{
  printf("Creating game instance\n");
  Game game;
  printf("Setting up game\n");
  game.setup();
  printf("Game setup complete!\n");
  while(game.running)
  {
    game.update();
  }
  printf("Successfully exited. Have a nice day!\n");
  return RC_SUCCESS;
}


