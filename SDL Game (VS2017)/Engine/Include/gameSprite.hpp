#pragma once
#include <vector>

class gameImage;
class gameRenderer;
class gameVector2;

class gameSprite
{
public:
	gameSprite(gameImage* images[]);

	void addImage(gameImage* image);

	gameImage* getImage(int index);

	void renderSpecific(int index, gameRenderer* renderer, gameVector2* position);

	void render(gameRenderer* renderer, gameVector2* position);

	int animStates();

	int getCurrentState();

	~gameSprite();
private:
	std::vector<gameImage*> spriteImages;
	int currentState = 0;
};