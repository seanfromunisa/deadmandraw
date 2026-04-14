#pragma once
#include <iostream>
class Player
{
	std::string name;
	int score;

public:
	Player();
	~Player();
	bool playCard();
	bool bankCard();
	void displayPlayerBank() const;
};

