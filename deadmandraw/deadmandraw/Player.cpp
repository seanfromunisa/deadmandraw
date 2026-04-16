#include "Player.h"
#include "Card.h"
#include <iostream>
#include <map>

Player::Player()
{
	int _score = 0;
	std::string names[] = { "Luffy", "Zoro", "Nami", "Usopp", "Sanji", "Chopper", "Robin", "Franky", "Brook", "Jinbe" };
	std::string _name = names[rand() % 10];
	CardCollection playerBank = {};
	CardCollection playArea = {};
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

bool Player::playCard(std::shared_ptr<Card> card)
{
	printf("%s draws a %s", _name, card->toString());
	bool notBust = true;
	for (std::shared_ptr<Card> playedCard : playArea) {
		if (playedCard->type() == card->type()) {
			notBust = false;
		}
	}
	if (notBust == false) {
		printf("BUST! %s loses all cards in play area.", _name);
		// move all cards from play area to discard pile
		playArea.clear();
	}
	else {
		playArea.push_back(card);
	}
	return notBust;
}

void Player::bankCards()
{

}

int Player::calculateScore()
{
	std::map<int, int> scoredCards;
	for (int suit = 0; suit < 10; suit++) {
		scoredCards[suit] = 0;
	}

	for (std::shared_ptr<Card> card : playerBank) {
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
