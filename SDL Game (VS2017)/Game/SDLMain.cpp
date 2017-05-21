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

	gameWindow window("Main Window", new gameVector2(640, 512), true);

	gameRenderer renderer(&window);

	gameImage image(&renderer, "s1.png");
	gameImage image2(&renderer, "s4.png");

	gameSprite sprite(&image);
	gameSprite sprite2(&image2);
	sprite.setPosition(new gameVector2(20, 20));
	sprite2.setPosition(new gameVector2(140, 20));
	sprite.setActive();
	sprite2.setActive();

	stateList states = { "one", "two" };
	spriteList sprites = { sprite, sprite2 };
	gameAnimator animator(states);
	animator.addSprites("one", sprites);
	
	renderer.setColor(0, 150, 136, 255);

	while (exit != true)
	{
		renderer.clear();
		sprite.render();
		sprite2.render();
		renderer.update();

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