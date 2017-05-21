#include <SDL_image.h>
#include <iostream>

#include "gameInit.hpp"
#include "gameWindow.hpp"
#include "gameImage.hpp"
#include "gameSprite.hpp"
#include "gameRenderer.hpp"
#include "gameVector2.hpp"
#include "gameAnimator.hpp"

#ifdef main
#undef main
#endif

int main(int argc, char* argv[])
{
	bool exit = false;
	SDL_Event mainEvent;

	if (!gameInit())
	{
		std::cout << "Failed to Initialize. Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	gameWindow* window = new gameWindow("Main Window", new gameVector2(640, 512), true);

	gameRenderer* renderer = new gameRenderer(window);
	renderer->setColor(0, 150, 136, 255);

	gameSprite* sprite = new gameSprite(new gameImage(renderer, "./s1.png"));
	sprite->setPosition(new gameVector2(20, 20));
	sprite->setActive();

	while (exit != true)
	{

		SDL_Delay(18);	//theres still a small memory leak but this simple delay slows it down to a point where it doesn't matter
		renderer->clear();
		sprite->render();
		renderer->update();

		while (SDL_PollEvent(&mainEvent))
		{
			if (mainEvent.type == SDL_QUIT)
			{
				exit = true;
			}
		}
	}

	delete sprite;
	delete renderer;	//this might not be needed
	delete window;
	gameExit();
	return 0;
}