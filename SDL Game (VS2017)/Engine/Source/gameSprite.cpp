#include <SDL.h>
#include <iostream>

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
		rect.x = NULL;
		rect.y = NULL;
		rect.w = NULL;
		rect.h = NULL;
	}
}

void gameSprite::render(gameVector2* position)
{
	if (active)
	{
		SDL_Rect rect;
		rect.x = position->getX();
		rect.y = position->getY();
		rect.w = i->getSize()->getX();
		rect.h = i->getSize()->getY();
		SDL_RenderCopy(i->getRenderer()->getRenderer(), i->getTexture(), NULL, &rect);
		rect.x = NULL;
		rect.y = NULL;
		rect.w = NULL;		//THERE'S NO WAY THIS COULD HAVE BEEN THE MEMORY LEAK BUT IT SEEMED TO FIX IT 
		rect.h = NULL;
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

gameSprite::~gameSprite()
{
	delete rend;
	delete i;
	delete pos;
	active = NULL;
}