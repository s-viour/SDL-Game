//gameRenderer | class for allowing SDL_Renderers to interact with the rest of the engine
#pragma once
#include <SDL.h>

class gameWindow;
class gameImage;

class gameRenderer
{
public:
	gameRenderer(gameWindow* window);

	void setColor(Uint32 r, Uint32 g, Uint32 b, Uint32 a);

	void clear();

	void update();

	SDL_Renderer* getRenderer();

	~gameRenderer();

private:
	SDL_Renderer *renderer;
};
