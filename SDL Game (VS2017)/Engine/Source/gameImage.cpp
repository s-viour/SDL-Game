#include <SDL_image.h>
#include <iostream>

#include "gameImage.hpp"
#include "gameRenderer.hpp"
#include "gameVector2.hpp"

gameImage::gameImage(gameRenderer* renderer, char* path)	//If a path is given, load it
{
	if (path == "")
	{
		return;
	}

	rend = renderer;
	loadFromFile(path);
}

gameImage::gameImage(gameRenderer* renderer)	//If a path is not given, just set the renderer
{
	rend = renderer;
	return;
}

SDL_Texture* gameImage::getTexture()	//Does exactly what you would think it would do
{
	return texture;
}

void gameImage::loadFromFile(char* file)	//Loads the image and sets the private variable: texture to an SDL_Texture
{
	SDL_Surface* image = IMG_Load(file);

	if (image != NULL)
	{
		texture = SDL_CreateTextureFromSurface(rend->getRenderer(), image);
		SDL_FreeSurface(image);
		image = nullptr;	//Deallocate the temporary buffer that stored the raw image
	}
}

gameVector2 gameImage::getSize()		//Returns a gameVector2 with the width and height of the image
{																		//This particular function caused a massive memory leak that made me very upset
	int w, h;													//I still don't understand why the leak happened

	SDL_QueryTexture(texture, NULL, NULL, &w, &h);

	return gameVector2(w, h);		//THIS WAS THE MEMORY LEAK, DO NOT RETURN NEW OBJECTS EVER AGAIN, MATT |
									//original text: return new gameVector2(w, h) | and the function type was instead gameVector2*

}

SDL_Renderer* gameImage::getRenderer()	//This documentation is very simple isn't it?
{
	return rend->getRenderer();
}

gameImage::~gameImage()
{
	SDL_DestroyTexture(texture);
}
