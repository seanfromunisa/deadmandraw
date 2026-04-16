#include "Player.h"
#include "Card.h"
#include <iostream>
#include <map>

Player::Player()
{
	int score = 0;
	std::string names[] = { "Luffy", "Zoro", "Nami", "Usopp", "Sanji", "Chopper", "Robin", "Franky", "Brook", "Jinbe" };
	std::string name = names[rand() % 10];
}

std::string Player::getName() const
{
	return name;
}

int Player::getScore() const
{
	return score;
}

int Player::calculateScore()
{
	std::map<Card, int> scoredCards;
	for (int i : Card) {
		scoredCards[i] = 0;
	}

	for (Card i : playerBank) {
		CardType currentCardType = i.getType();
		if (scoredCards[currentCardType] < i.value()) {
			scoredCards[currentCardType] = i.value();
		}
	}

	int total = 0;
	for (int i : scoredCards.value) {
		total = total + i;
	}

	score = total;
	
	return total;
}
