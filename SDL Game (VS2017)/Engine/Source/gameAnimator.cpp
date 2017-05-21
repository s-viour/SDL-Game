#include "gameAnimator.hpp"
#include "gameSprite.hpp"
#include <iostream>

gameAnimator::gameAnimator(std::vector<std::string> states)
{
	for (int i = 0; i < states.size(); i++)
	{
		st.push_back(states.at(i));
	}
}

void gameAnimator::addSprites(std::string state, std::vector<gameSprite> sprites)	//how do i do this
{
	int numberToGoto;

	for (int i = 0; i < st.size(); i++)
	{
		if (st.at(i) == state)
		{
			numberToGoto = i;
		}
	}

	std::cout << numberToGoto << " THIS IS THE NUMBER OF THE THING, IT SHOULD BE 0\n";

	for (int i = 0; i < stateLists.size(); i++)
	{
		stateLists.at(numberToGoto).push_back(sprites.at(i));		//god i hope this works | update: it didn't work
	}																//whatever vs did caused the debugger to crash and the process will no longer close 
}																	//access is denied and if i've accidentally found a security vulnerability i will be rich if i can explain what happened
																	//21.1 megabytes of memory are now permenantly occupied by SDL Game(VS2017).exe
