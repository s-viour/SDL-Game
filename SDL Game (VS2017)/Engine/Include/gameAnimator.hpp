#pragma once
#include <vector>

class gameSprite;

typedef std::vector<std::string> stateList;
typedef std::vector<gameSprite> spriteList;
typedef std::string state;

class gameAnimator
{
public:
	gameAnimator(std::vector<std::string> states);

	void addSprites(std::string state, std::vector<gameSprite> sprites);

	void setState(std::string state);

	std::string getState();

private:

	std::vector<std::string> st;

	std::vector<std::vector<gameSprite>> stateLists;	//this might not be a good idea but it's all i can think of
};