#pragma once
#include <iostream>
class Player
{
	std::string name;
	int score;

public:
	Player();
	~Player();
	std::string getName() const;
	int getScore() const;
	bool playCard();
	bool bankCard();
	void displayPlayerBank() const;
	int calculateScore();
};

