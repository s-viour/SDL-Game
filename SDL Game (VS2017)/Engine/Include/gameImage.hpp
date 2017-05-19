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

	void loadFromFile(char* file);

	gameVector2* getSize();

	gameRenderer* getRenderer();

	~gameImage();
private:
	gameRenderer* rend;
	SDL_Texture* texture;
};