#include <SDL_image.h>
#include <iostream>
#include "gameImage.h"
#include "gameRenderer.h"

gameImage::gameImage(std::string path, gameRenderer* renderer)
{
	SDL_Surface* image = IMG_Load(path.c_str());

	if (image == NULL)
	{
		std::cout << "Failed to load image: " << path << " Error: " << IMG_GetError() << std::endl;
		return;
	}

	texture = SDL_CreateTextureFromSurface(renderer->getRenderer(), image);
	SDL_FreeSurface(image);
}

SDL_Texture* gameImage::getTexture()
{
	return texture;
}

gameImage::~gameImage()
{
	SDL_DestroyTexture(texture);
}
