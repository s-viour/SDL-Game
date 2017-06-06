#include "gameInit.hpp"

bool gameInit()	//Initializes video and png images, may be updated later to include SDL_INIT_EVERYTHING
{								//Returns true if everything works correctly
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		success = false;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		success = false;
	}

	return success;
}

void gameExit()		//Quits sdl and img
{
	SDL_Quit();
	IMG_Quit();
}
