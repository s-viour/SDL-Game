#include "gameWindow.hpp"

#include "gameVector2.hpp"

gameWindow::gameWindow(char* name, gameVector2* size, bool shown) //creates a window and if shown == true shows the window
{																																	//size is in gameVector2 form
	windowName = name;
	windowSize = size;

	makeWindow();

	if (shown)
	{
		openWindow();
	}
}

void gameWindow::makeWindow()	//function to create a window object and store it within this class
{
	window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowSize->getX(), windowSize->getY(), SDL_WINDOW_HIDDEN);
}

void gameWindow::openWindow()	//don't let flies in! this shows the window
{
	SDL_ShowWindow(window);
}

void gameWindow::closeWindow()	//this closes the window but does not delete the window
{
	SDL_HideWindow(window);
}

void gameWindow::deleteWindow()	//this destroys the window - i should probably have this set window to null also
{
	SDL_DestroyWindow(window);
	window = NULL;
}

void gameWindow::updateWindow() //updates the window surface similar to renderer.update() but does not send it to the gpu
{
	SDL_UpdateWindowSurface(window);
}

SDL_Window* gameWindow::getWindow()	//returns the SDL_Window object
{
	return window;
}

SDL_Surface* gameWindow::getWindowSurface()	//returns the SDL_Surface inside the window
{
	return SDL_GetWindowSurface(window);
}

gameWindow::~gameWindow()	//Destroys window and whatnot
{
	SDL_DestroyWindow(window);
	window = NULL;
	windowName = NULL;
	windowSize = NULL;
}
