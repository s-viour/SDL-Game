#pragma once
#include <SDL.h>

class gameWindow
{
public:
	gameWindow(char* name, int width, int height, bool shown);

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
	int windowWidth;
	int windowHeight;
};