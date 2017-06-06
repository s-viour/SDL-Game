//gameVector2 | just a regular vector2 class for storing x and y values
#pragma once

class gameVector2
{
public:
	gameVector2(int xval, int yval);

	int getX();

	int getY();

	~gameVector2();
private:
	int x;
	int y;
};
