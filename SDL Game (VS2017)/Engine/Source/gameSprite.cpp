#include <SDL.h>
#include <iostream>

#include "gameSprite.hpp"
#include "gameVector2.hpp"
#include "gameRenderer.hpp"
#include "gameImage.hpp"

gameSprite::gameSprite(gameImage* image)	//Sets the underlying gameImage to the arguments
{
	i = image;
}

void gameSprite::render()	//renders the sprite with the coordinates stored with setPosition()
{
	if (active)
	{
		SDL_Rect rect;
		rect.x = pos->getX();
		rect.y = pos->getY();
		rect.w = i->getSize().getX();
		rect.h = i->getSize().getY();
		SDL_RenderCopy(i->getRenderer(), i->getTexture(), NULL, &rect);
		rect.x = NULL;	//Clean up after urself
		rect.y = NULL;
		rect.w = NULL;
		rect.h = NULL;
	}
}

void gameSprite::render(gameVector2* position)	//renders the sprite with the given vector2 as an override
{
	if (active)
	{
		SDL_Rect rect;
		rect.x = position->getX();
		rect.y = position->getY();
		rect.w = i->getSize().getX();
		rect.h = i->getSize().getY();
		SDL_RenderCopy(i->getRenderer(), i->getTexture(), NULL, &rect);
		rect.x = NULL;
		rect.y = NULL;
		rect.w = NULL;
		rect.h = NULL;
	}
}

void gameSprite::setPosition(gameVector2* position)	//Sets the position to be used with render()
{
	pos = position;
}

gameVector2* gameSprite::getPosition()	//returns a vector2 of the current position of the sprite
{
	return new gameVector2(pos->getX(), pos->getY());
}

void gameSprite::setActive()		//if it is active, it will render
{
	active = true;
}

void gameSprite::setInactive()	//if it is inactive, the sprite will not be rendered, but will still have position
{
	active = false;
}

gameSprite::~gameSprite()	//deletes everything and cleans up and stuff
{
	delete rend;
	delete i;
	delete pos;
	active = NULL;
}
