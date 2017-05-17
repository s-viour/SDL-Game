#include "gameSprite.hpp"

#include "gameImage.hpp"
#include "gameRenderer.hpp"
#include "gameVector2.hpp"

gameSprite::gameSprite(gameImage* images[])
{
	for (int i = 0; i < sizeof(images); i++)
	{
		addImage(images[i]);
	}
}

void gameSprite::addImage(gameImage* image)
{
	spriteImages.push_back(image);
}

gameImage* gameSprite::getImage(int index)
{
	return spriteImages.at(index);
}

void gameSprite::renderSpecific(int index, gameRenderer* renderer, gameVector2* position)
{
	SDL_Rect dest;
	dest.x = position->getX();
	dest.y = position->getY();
	dest.w = getImage(index)->getSize()->getX();
	dest.h = getImage(index)->getSize()->getY();

	SDL_RenderCopy(renderer->getRenderer(), getImage(index)->getTexture(), NULL, &dest);
}

void gameSprite::render(gameRenderer* renderer, gameVector2* position)
{
	renderSpecific(getCurrentState(), renderer, position);
	currentState++;
}

int gameSprite::animStates()
{
	return spriteImages.size();
}

int gameSprite::getCurrentState()
{
	if (currentState == animStates())
	{
		currentState = 0;
	}

	return currentState;
}

gameSprite::~gameSprite()
{
	spriteImages.clear();
}