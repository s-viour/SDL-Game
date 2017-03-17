#pragma once


class gameVector2
{
public:
	gameVector2(int xval, int yval);

	int getX();

	int getY();
private:
	int x;
	int y;
};