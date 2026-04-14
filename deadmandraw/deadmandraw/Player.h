#pragma once
#include <iostream>
class Player
{
	std::string name;
	int score;

public:
	Player();
	~Player();
	const std::string name() const;
	const int score() const;
	bool playCard();
	bool bankCard();
	void displayPlayerBank() const;
	int calculateScore();
};

