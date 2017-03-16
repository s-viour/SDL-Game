#pragma once
#include <SDL.h>
#include <string>

class gameRenderer;

class gameImage
{
public:
	gameImage(std::string path, gameRenderer* renderer);

	SDL_Texture* getTexture();

	~gameImage();
private:
	SDL_Texture* texture;
};