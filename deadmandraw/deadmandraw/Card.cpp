#define _CRT_SECURE_NO_WARNINGS
#include "Card.h"
#include "Player.h"
#include "Game.h"
#include <string>
#include <map>

Card::~Card()
{
}

// Returns string of "Type(Value)"
std::string Card::toString() const
{
	return _stringType + "(" + std::to_string(_value) + ")";
}

// Returns type
const Card::CardType& Card::type() const
{
	return _type;
}

// Returns value
int Card::value() const
{
	return _value;
}

// Play function to be overwritten with child card abilities
void Card::play(Game& game, Player& player)
{
}

// Displays a player's bank and allows player to choose the card the function will return
std::shared_ptr<Card> Card::grabFromBank(Player& player)
{
	// Map of highest value card for each type in bank
	std::map<CardType, std::shared_ptr<Card>> availableCards;
	for (std::shared_ptr<Card> card : player.playerBank) {
		CardType currentCardType = card->type();
		if (availableCards[currentCardType]->value() < card->value()) {
			availableCards[currentCardType] = card;
		}
	}
	
	// Vector of highest value card for each type in bank
	std::vector<std::shared_ptr<Card>> finalCards;
	for (const auto& keyValuePair : availableCards) {
		finalCards.push_back(keyValuePair.second);
	}

	// Print and number each available option for the player to choose to return
	for (int i = 0; i < static_cast<int>(finalCards.size()); i++) {
		printf("(%d) %s\n", (i + 1), finalCards[i]->toString().c_str());
	}

	int cardPick = 0;
	printf("Which card do you pick? ");
	scanf("%d", &cardPick);

	// -1 to match vector position
	return finalCards[cardPick - 1];
}

// Empty function for card abilities that activate at time of banking
void Card::willAddToBank(Game& game, Player& player)
{
}
