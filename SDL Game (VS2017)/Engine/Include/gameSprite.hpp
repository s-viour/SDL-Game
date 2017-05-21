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

	gameVector2* getPosition();

	void setActive();

	void setInactive();

	~gameSprite();

private:
	gameRenderer* rend;
	gameImage* i;
	gameVector2* pos;
	bool active;
};