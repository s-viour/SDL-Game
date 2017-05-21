#include "gameWindow.hpp"

#include "gameVector2.hpp"

gameWindow::gameWindow(char* name, gameVector2* size, bool shown)
{
	windowName = name;
	windowSize = size;

	makeWindow();

	if (shown)
	{
		openWindow();
	}
}

void gameWindow::makeWindow()
{	
	window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowSize->getX(), windowSize->getY(), SDL_WINDOW_HIDDEN);
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
	windowSize = NULL;
}