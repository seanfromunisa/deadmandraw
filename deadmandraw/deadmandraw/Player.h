#pragma once
#include <iostream>
class Player
{
	std::string _name;
	int _score;

public:
	Player();
	~Player();
	std::string name() const;
	int score() const;
	bool playCard();
	bool bankCard();
	void displayPlayerBank() const;
	int calculateScore();
};

