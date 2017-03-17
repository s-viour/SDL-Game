#include "gameRenderer.hpp"
#include "gameWindow.hpp"
#include "gameImage.hpp"

gameRenderer::gameRenderer(gameWindow* window)
{
	renderer = SDL_CreateRenderer(window->getWindow(), -1, SDL_RENDERER_ACCELERATED);
}

void gameRenderer::setColor(Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void gameRenderer::clear()
{
	SDL_RenderClear(renderer);
}

void gameRenderer::update()
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer* gameRenderer::getRenderer()
{
	return renderer;
}

gameRenderer::~gameRenderer()
{
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	
}
