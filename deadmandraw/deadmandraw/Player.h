#pragma once
#include <string>
class Player
{
	std::string name;
	int score;

public:
	Player();
	~Player();
	bool playCard();
	bool bankCard();
	void displayPlayerBank();
};

