#include <SDL.h>

#include "gameSprite.hpp"
#include "gameVector2.hpp"
#include "gameRenderer.hpp"
#include "gameImage.hpp"

gameSprite::gameSprite(gameImage* image)
{
	i = image;
}

void gameSprite::render()
{
	if (active)
	{
		SDL_Rect rect;
		rect.x = pos->getX();
		rect.y = pos->getY();
		rect.w = i->getSize()->getX();
		rect.h = i->getSize()->getY();
		SDL_RenderCopy(i->getRenderer()->getRenderer(), i->getTexture(), NULL, &rect);
	}
}

void gameSprite::render(gameVector2* position)
{
	if (active)
	{
		SDL_Rect rect;
		rect.x = pos->getX();
		rect.y = pos->getY();
		rect.w = i->getSize()->getX();
		rect.h = i->getSize()->getY();
		SDL_RenderCopy(i->getRenderer()->getRenderer(), i->getTexture(), NULL, &rect);
	}
}

void gameSprite::setPosition(gameVector2* position)
{
	pos = position;
}

gameVector2* gameSprite::getPosition()
{
	return new gameVector2(pos->getX(), pos->getY());
}

void gameSprite::setActive()
{
	active = true;
}

void gameSprite::setInactive()
{
	active = false;
}