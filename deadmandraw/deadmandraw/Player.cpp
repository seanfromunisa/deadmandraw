#include "Player.h"
#include "Card.h"
#include <map>

Player::Player()
{
	int score = 0;
	std::string names[] = { "Luffy", "Zoro", "Nami", "Usopp", "Sanji", "Chopper", "Robin", "Franky", "Brook", "Jinbe" };
	std::string name = names[rand() % 10];
}

const std::string Player::name() const
{
	return name;
}

const int Player::score() const
{
	return score;
}

int Player::calculateScore()
{
	map< Card.CardType, int> scoredCards;
	for (int i : Card.CardType) {
		map[i] = 0;
	}

	for (int i : playerBank) {
		CardType currentCardType  = i.type();
		if (map[currentCardType] < i.value()) {
			map[currentCardType] = i.value();
		}
	}

	int total = 0;
	for (int i : map.value) {
		total = total + i;
	}

	score = total;
	
	return total;
}
