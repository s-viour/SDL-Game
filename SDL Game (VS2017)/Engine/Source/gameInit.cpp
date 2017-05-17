#include "gameInit.hpp"

bool gameInit()
{
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

void gameExit()
{
	SDL_Quit();
	IMG_Quit();
}