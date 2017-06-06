#include "gameRenderer.hpp"
#include "gameWindow.hpp"
#include "gameImage.hpp"

gameRenderer::gameRenderer(gameWindow* window)	//Creates an SDL_Renderer and stores it
{
	renderer = SDL_CreateRenderer(window->getWindow(), -1, SDL_RENDERER_ACCELERATED);
}

void gameRenderer::setColor(Uint32 r, Uint32 g, Uint32 b, Uint32 a)	//Sets the background color of the renderer
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void gameRenderer::clear()	//Clears all drawn objects on the screen and replaces it with the draw color
{
	SDL_RenderClear(renderer);
}

void gameRenderer::update()	//Updates the renderer : this would be called once in the main loop
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer* gameRenderer::getRenderer()	//Returns the renderer, useful for interfacing with other parts underlying in SDL
{
	return renderer;
}

gameRenderer::~gameRenderer()	//Destroys the renderer and sets it to NULL
{															//Though this sometimes throws an exception in VS2017s debug mode on program close
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

}
