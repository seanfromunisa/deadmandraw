#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

class Player
{
	typedef std::vector<std::shared_ptr<Card>> CardCollection;

	std::string _name;
	int _score;
	CardCollection _playerBank;
	CardCollection _playArea;

public:
	Player();
	~Player();
	std::string name() const;
	int score() const;
	bool playCard(CardCollection& cards);
	void bankCards();
	void displayPlayerBank() const;
	int calculateScore();
	void printPlayArea() const;
};