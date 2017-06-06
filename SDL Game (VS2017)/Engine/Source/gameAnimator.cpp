#include "gameAnimator.hpp"
#include "gameSprite.hpp"
#include <iostream>

gameAnimator::gameAnimator(std::vector<std::string> states)
{
	for (int i = 0; i < states.size(); i++)
	{
		st.push_back(states.at(i));											//Fill both of the vectors with values
		stateLists.push_back(std::vector<gameSprite*>()); //This is required to be filled with empty vectors to be accessed later
	}

	activeState = 0;	//Set both values to zero to avoid NULL problems
	activeRender = 0;
}

void gameAnimator::addSprites(std::string state, std::vector<gameSprite*> sprites)	//Complicated
{
	int numberToGoto;	//Store index value to "goto"

	for (int i = 0; i < st.size(); i++)
	{
		if (st.at(i) == state)
		{
			numberToGoto = i;	//Figure out which index is correct
		}
	}

	for (int i = 0; i < stateLists.size(); i++)		//Push back all the sprites to a certain state
	{
		stateLists.at(numberToGoto).push_back(sprites.at(i));		//god i hope this works | update: it didn't work
	}																//whatever vs did caused the debugger to crash and the process will no longer close
}																	//access is denied and if i've accidentally found a security vulnerability i will be rich if i can explain what happened
																	//21.1 megabytes of memory are now permenantly occupied by SDL Game(VS2017).exe

void gameAnimator::setState(std::string state)	//Sets the active state
{																								//Should be called during main loop to change states
	for (int i = 0; i < st.size(); i++)
	{
		if (st.at(i) == state)
		{
			activeState = i;
		}
	}
}

std::string gameAnimator::getState()	//Yeah
{
	return st[activeState];
}

void gameAnimator::setRenderPos(gameVector2* pos)	//Sets the render position for the sprites
{																									//Should be called during main loop to create movement
	position = pos;
}

void gameAnimator::renderNext()		//Renders the next sprite in the active state
{
	int max = stateLists.at(activeState).size();		//Stores index of the last state so it can be reverted to the first one

	stateLists.at(activeState).at(activeRender)->render(position);	//Render the Sprite

	activeRender += 1;
	if (activeRender >= max)	//Increment the active render target and if it is 'max' set it to 0
	{
		activeRender = 0;
	}
}

//	TODO: ADD DECONSTRUCTOR THIS IMPORTANT :TODO //
