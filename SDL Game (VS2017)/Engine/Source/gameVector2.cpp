#include <SDL.h>
#include "gameVector2.hpp"

gameVector2::gameVector2(int xval, int yval)	//sets x and y
{
	x = xval;
	y = yval;
}

int gameVector2::getX()	//returns x
{
	return x;
}

int gameVector2::getY()	//returns y
{
	return y;
}

gameVector2::~gameVector2()	//sets both to NULL
{
	x = NULL;
	y = NULL;
}
