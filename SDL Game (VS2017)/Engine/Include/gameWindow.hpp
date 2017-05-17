#pragma once
#include <SDL.h>

class gameVector2;

class gameWindow
{
public:
	gameWindow(char* name, gameVector2* size, bool shown);

	void makeWindow();

	void openWindow();

	void closeWindow();

	void deleteWindow();

	void updateWindow();

	SDL_Window* getWindow();

	SDL_Surface* getWindowSurface();

	~gameWindow();
private:
	SDL_Window* window;

	char* windowName;
	gameVector2* windowSize;
};