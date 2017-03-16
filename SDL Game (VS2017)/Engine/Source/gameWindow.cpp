#include "gameWindow.hpp"

gameWindow::gameWindow(char* name, int width, int height, bool shown)
{
	windowName = name;
	windowWidth = width;
	windowHeight = height;

	makeWindow();

	if (shown)
	{
		openWindow();
	}
}

void gameWindow::makeWindow()
{	
	window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_HIDDEN);
}

void gameWindow::openWindow()
{
	SDL_ShowWindow(window);
}

void gameWindow::closeWindow()
{
	SDL_HideWindow(window);
}

void gameWindow::deleteWindow()
{
	SDL_DestroyWindow(window);
}

void gameWindow::updateWindow()
{
	SDL_UpdateWindowSurface(window);
}

SDL_Window* gameWindow::getWindow()
{
	return window;
}

SDL_Surface* gameWindow::getWindowSurface()
{
	return SDL_GetWindowSurface(window);
}

gameWindow::~gameWindow()
{
	SDL_DestroyWindow(window);

	window = NULL;
	windowName = NULL;
	windowWidth = NULL;
	windowHeight = NULL;
}