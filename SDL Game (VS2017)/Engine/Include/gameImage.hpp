#pragma once
#include <SDL.h>

class gameRenderer;
class gameVector2;

class gameImage
{
public:
	gameImage(gameRenderer* renderer, char* path);

	gameImage(gameRenderer* renderer);

	SDL_Texture* getTexture();

	void loadFromFile(gameRenderer* renderer, char* file);

	gameVector2* getSize();

	~gameImage();
private:
	SDL_Texture* texture;
};