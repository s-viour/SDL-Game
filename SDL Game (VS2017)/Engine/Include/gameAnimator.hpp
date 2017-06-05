#pragma once
#include <vector>

class gameSprite;
class gameVector2;

class gameAnimator
{
public:
	gameAnimator(std::vector<std::string> states);

	void addSprites(std::string state, std::vector<gameSprite*> sprites);

	void setState(std::string state);

	std::string getState();

	void setRenderPos(gameVector2* pos);

	void renderNext();

private:

	std::vector<std::string> st;

	gameVector2* position;

	int activeState;

	int activeRender;

	std::vector<std::vector<gameSprite*>> stateLists;	//this might not be a good idea but it's all i can think of
};