#pragma once
#include <iostream>
#include <vector>

class Card;
class Game;

class Player
{
public:
	typedef std::vector<Card> CardCollection;

	CardCollection playerBank;
	CardCollection playArea;

protected:
	std::string _name;
	int _score;

public:
	Player();
	~Player();
	std::string name() const;
	int score() const;
	bool playCard(Card &card, Game &game, Player &player);
	void bankCards(Game& game, Player& player);
	void displayPlayerBank();
	int calculateScore();
	void printPlayArea() const;
};