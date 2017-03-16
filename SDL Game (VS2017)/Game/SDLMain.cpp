#include <SDL_image.h>
#include <iostream>

#include "gameWindow.hpp"
#include "gameImage.hpp"
#include "gameRenderer.hpp"

#ifdef main
#undef main
#endif

gameWindow* window;
gameRenderer* renderer;

bool gameInit()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
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

int main(int argc, char* argv[])
{
	bool exit = false;
	SDL_Event mainEvent;

	if (!gameInit())
	{
		std::cout << "Failed to Initialize. Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	window = new gameWindow("Main Window", 640, 480, true);
	renderer = new gameRenderer(window);
	renderer->setColor(0, 140, 160, 255);

	while (exit != true)
	{
		renderer->clear();
		renderer->update();

		while (SDL_PollEvent(&mainEvent))
		{
			if (mainEvent.type == SDL_QUIT)
			{
				exit = true;
			}
		}
	}

	gameExit();
	return 0;
}