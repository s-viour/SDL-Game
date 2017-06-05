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
	gameSprite* sprite2 = new gameSprite(new gameImage(renderer, "./s2.png"));
	gameSprite* sprite3 = new gameSprite(new gameImage(renderer, "./s3.png"));
	gameSprite* sprite4 = new gameSprite(new gameImage(renderer, "./s4.png"));
	sprite->setActive();
	sprite2->setActive();
	sprite3->setActive();
	sprite4->setActive();

	
	gameAnimator* animator = new gameAnimator({ "state1", "state2" });
	animator->addSprites("state1", { sprite, sprite2 });		//omg it works
	animator->addSprites("state2", { sprite3, sprite4 });

	animator->setRenderPos(new gameVector2(40, 40));
	animator->setState("state1");


	while (exit != true)
	{

		SDL_Delay(18);	//theres still a small memory leak but this simple delay slows it down to a point where it doesn't matter
		renderer->clear();
		animator->renderNext();
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