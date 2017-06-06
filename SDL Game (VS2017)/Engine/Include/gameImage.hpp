//gameImage | abstracted interface to allow SDL_Images to interact with the rest of the engine
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

	gameVector2 getSize();

	SDL_Renderer* getRenderer();

	~gameImage();
private:
	gameRenderer* rend;
	SDL_Texture* texture;
};
