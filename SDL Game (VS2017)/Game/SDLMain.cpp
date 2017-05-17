#include <iostream>

#include "gameInit.hpp"
#include "gameWindow.hpp"
#include "gameImage.hpp"
#include "gameRenderer.hpp"
#include "gameVector2.hpp"
#include "gameSprite.hpp"

#ifdef main
#undef main
#endif

gameVector2* winSize;
gameWindow* window;
gameRenderer* renderer;
gameImage* images[4];
gameSprite* sprite;

float position;

void figurePosition()
{
	if (position > 1024)
	{
		position = 0;
	}

	else
	{
		position += 0.1;
	}
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

	winSize = new gameVector2(1024, 768);

	window = new gameWindow("Main Window", winSize, true);

	renderer = new gameRenderer(window);

	images[0] = new gameImage(renderer, "s1.png");
	images[1] = new gameImage(renderer, "s2.png");
	images[2] = new gameImage(renderer, "s3.png");
	images[3] = new gameImage(renderer, "s4.png");

	sprite = new gameSprite(images);
	
	renderer->setColor(255, 255, 255, 255);

	while (exit != true)
	{
		renderer->clear();
		sprite->render(renderer, new gameVector2(position, 0));
		sprite->render(renderer, new gameVector2(position, 200));
		sprite->render(renderer, new gameVector2(position, 400));
		sprite->render(renderer, new gameVector2(position, 600));
		renderer->update();

		figurePosition();

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