#include "Player.h"
#include "Card.h"
#include <iostream>
#include <map>

Player::Player()
{
	int _score = 0;
	std::string names[] = { "Luffy", "Zoro", "Nami", "Usopp", "Sanji", "Chopper", "Robin", "Franky", "Brook", "Jinbe" };
	std::string _name = names[rand() % 10];
	CardCollection _playerBank = {};
	CardCollection _playArea = {};
}

Player::~Player()
{
}

std::string Player::name() const
{
	return _name;
}

int Player::score() const
{
	return _score;
}

bool Player::playCard(CardCollection& cards)
{

	return false;
}

int Player::calculateScore()
{
	std::map<int, int> scoredCards;
	for (int suit = 0; suit < 10; suit++) {
		scoredCards[suit] = 0;
	}

	for (std::shared_ptr<Card> card : _playerBank) {
		int currentCardType = card->type();
		if (scoredCards[currentCardType] < card->value()) {
			scoredCards[currentCardType] = card->value();
		}
	}

	int total = 0;
	for (const auto& keyValuePair : scoredCards) {
		total = total + keyValuePair.second;
	}

	_score = total;
	
	return total;
}
