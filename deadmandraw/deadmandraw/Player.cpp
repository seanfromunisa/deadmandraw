#include "Player.h"
#include "Card.h"
#include "Game.h"
#include <iostream>
#include <map>

Player::Player()
{
	int _score = 0;

	// Player name is randomly chosen from array of 10 options
	std::string names[] = { "Luffy", "Zoro", "Nami", "Usopp", "Sanji", "Chopper", "Robin", "Franky", "Brook", "Jinbe" };
	_name = names[rand() % 10];

	playerBank;
	playArea;
}

Player::~Player()
{
}

// Return name
std::string Player::name() const
{
	return _name;
}

// Return score
int Player::score() const
{
	return _score;
}

// Plays card from the play area, checking for a bust
bool Player::playCard(Card& card, Game& game, Player& player)
{
	printf("%s draws a %s", _name.c_str(), card.toString().c_str());

	// Boolean to be checked after verifying each card already in play area
	bool notBust = true;
	for (Card playedCard : playArea) {
		if (playedCard.type() == card.type()) {
			notBust = false;
		}
	}

	// If the player busts, their cards are sent to the discard pile
	if (notBust == false) {
		printf("BUST! %s loses all cards in play area.", _name.c_str());
		for (Card disCards : playArea) {
			game.discardPile.push_back(&disCards);
		}
		playArea.clear();
	}

	// If not, the card's ability activates
	else {
		card.play(game, player);
	}

	// Return whether the player busted
	return notBust;
}

// Invokes bank function of each card in play area, adding them to the player bank and then clearing the play area
void Player::bankCards(Game& game, Player& player)
{
	for (Card card : playArea) {
		card.willAddToBank(game, player);
		playerBank.push_back(card);
	}
	playArea.clear();
}

// Display each card in the player's bank and the player score
void Player::displayPlayerBank()
{
	printf("%s's Bank:\n", _name.c_str());
	for (Card card : playerBank) {
		printf("%s\n", card.toString().c_str());
	}
	printf("| Score: %d", static_cast<int>(calculateScore()));
}

// Calculates player score
int Player::calculateScore()
{
	// Map of highest value card for each type in bank
	std::map<Card::CardType, Card> scoredCards;
	for (Card card : playerBank) {
		Card::CardType currentCardType = card.type();
		if (scoredCards[currentCardType].value() < card.value()) {
			scoredCards[currentCardType] = card;
		}
	}

	// Total value of highest value cards
	int total = 0;
	for (const auto& keyValuePair : scoredCards) {
		total = total + keyValuePair.second.value();
	}

	// Update the player score and return the value
	_score = total;
	
	return total;
}

// Prints the toString of each card currently in the play area
void Player::printPlayArea() const
{
	printf("%s's Play Area:\n", _name.c_str());
	for (Card card : playArea) {
		printf("%s\n", card.toString().c_str());
	}
}
