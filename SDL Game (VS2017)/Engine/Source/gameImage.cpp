#include <SDL_image.h>
#include <iostream>

#include "gameImage.hpp"
#include "gameRenderer.hpp"
#include "gameVector2.hpp"

gameImage::gameImage(gameRenderer* renderer, char* path)
{
	if (path == "")
	{
		return;
	}

	loadFromFile(renderer, path);
}

gameImage::gameImage(gameRenderer* renderer)
{
	return;
}

SDL_Texture* gameImage::getTexture()
{
	return texture;
}

void gameImage::loadFromFile(gameRenderer* renderer, char* file)
{
	SDL_Surface* image = IMG_Load(file);

	if (image != NULL)
	{
		texture = SDL_CreateTextureFromSurface(renderer->getRenderer(), image);
	}
}

gameVector2* gameImage::getSize()
{
	int w, h;

	SDL_QueryTexture(texture, NULL, NULL, &w, &h);

	return new gameVector2(w, h);
}

gameImage::~gameImage()
{
	SDL_DestroyTexture(texture);
}
