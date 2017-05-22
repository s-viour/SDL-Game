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

	rend = renderer;
	loadFromFile(path);
}

gameImage::gameImage(gameRenderer* renderer)
{
	rend = renderer;
	return;
}

SDL_Texture* gameImage::getTexture()
{
	return texture;
}

void gameImage::loadFromFile(char* file)
{
	SDL_Surface* image = IMG_Load(file);

	if (image != NULL)
	{
		texture = SDL_CreateTextureFromSurface(rend->getRenderer(), image);
		SDL_FreeSurface(image);
		image = nullptr;
	}
}

gameVector2 gameImage::getSize()
{
	int w, h;

	SDL_QueryTexture(texture, NULL, NULL, &w, &h);

	return gameVector2(w, h);		//THIS WAS THE MEMORY LEAK, DO NOT RETURN NEW OBJECTS EVER AGAIN, MATT | 
									//original text: return new gameVector2(w, h) | and the function type was instead gameVector2*

}

SDL_Renderer* gameImage::getRenderer()
{
	return rend->getRenderer();
}

gameImage::~gameImage()
{
	SDL_DestroyTexture(texture);
}
