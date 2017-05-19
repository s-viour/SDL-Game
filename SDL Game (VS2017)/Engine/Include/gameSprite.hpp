#pragma once
#include <SDL.h>

class gameRenderer;
class gameImage;
class gameVector2;

class gameSprite
{
public:
	gameSprite(gameImage* image);

	void render();

	void render(gameVector2* position);

	void setPosition(gameVector2* position);

	void setActive();

	void setInactive();

private:
	gameRenderer* rend;
	gameImage* i;
	gameVector2* pos;
	bool active;
};