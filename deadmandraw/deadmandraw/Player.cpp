#include "Player.h"
#include "Card.h"
#include <iostream>
#include <map>

Player::Player()
{
	int _score = 0;
	std::string names[] = { "Luffy", "Zoro", "Nami", "Usopp", "Sanji", "Chopper", "Robin", "Franky", "Brook", "Jinbe" };
	std::string _name = names[rand() % 10];
}

std::string Player::name() const
{
	return _name;
}

int Player::score() const
{
	return _score;
}

int Player::calculateScore()
{
	std::map<int, int> scoredCards;
	for (int i = 0; i < 10; i++) {
		scoredCards[i] = 0;
	}

	for (Card i : playerBank) {
		int currentCardType = i.type();
		if (scoredCards[currentCardType] < i.value()) {
			scoredCards[currentCardType] = i.value();
		}
	}

	int total = 0;
	for (const auto& keyValuePair : scoredCards) {
		total = total + keyValuePair.second;
	}

	_score = total;
	
	return total;
}
