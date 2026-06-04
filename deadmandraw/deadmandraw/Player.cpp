#include "Player.h"
#include "Card.h"
#include "Game.h"
#include <iostream>
#include <map>

Player::Player()
{
	_score = 0;
	_notBust = true;

	// Seed based on time (mmmm seed)
	srand(time(NULL));

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
bool Player::playCard(std::shared_ptr<Card> card, Game& game, Player& player)
{
	printf("%s draws a %s\n", _name.c_str(), card->toString().c_str());

	// Boolean to be checked after verifying each card already in play area
	_notBust = true;
	for (std::shared_ptr<Card> playedCard : playArea) {
		if (playedCard->type() == card->type()) {
			_notBust = false;
		}
	}

	// The card is added to the play area
	playArea.push_back(card);

	// If the player busts, their cards are sent to the discard pile
	if (_notBust == false) {
		printf("BUST! %s loses all cards in play area.\n", _name.c_str());
		for (std::shared_ptr<Card> disCards : playArea) {
			game.discardPile.push_back(disCards);
		}
		playArea.clear();
	}

	// If not, the card's ability activates
	else {
		card->play(game, player);
	}

	// Return whether the player busted
	return _notBust;
}

// Changes bool _notBust. For card abilities to access
void Player::setNotBust(bool setBool)
{
	_notBust = setBool;
}

// Invokes bank function of each card in play area, adding them to the player bank and then clearing the play area
void Player::bankCards(Game& game, Player& player)
{
	for (std::shared_ptr<Card> card : playArea) {
		card->willAddToBank(game, player);
		playerBank.push_back(card);
	}
	playArea.clear();
}

// Display each card in the player's bank and the player score
void Player::displayPlayerBank()
{
	// Map of card vectors, each pertaining to a particular card type
	std::map<Card::CardType, CardCollection> cardsInBank;
	for (std::shared_ptr<Card> card : playerBank) {
		Card::CardType currentCardType = card->type();
		cardsInBank[currentCardType].push_back(card);
	}

	printf("%s's Bank:\n", _name.c_str());

	// Each set of cards in bank will be printed on a single line, seperated by type
	for (const auto& keyValuePair : cardsInBank) {
		for (std::shared_ptr<Card> card : keyValuePair.second) {
			printf(" %s", card->toString().c_str());
		}
		printf("\n");
	}

	printf("| Score: %d\n", static_cast<int>(calculateScore()));
}

// Calculates player score
int Player::calculateScore()
{
	// Map of highest value card for each type in bank
	std::map<Card::CardType, std::shared_ptr<Card>> scoredCards;
	for (std::shared_ptr<Card> card : playerBank) {
		Card::CardType currentCardType = card->type();
		if (scoredCards[currentCardType] != nullptr) {
			if (scoredCards[currentCardType]->value() < card->value()) {
				scoredCards[currentCardType] = card;
			}
		}

		// If the card type does not yet exist in the map, it is added
		else {
			scoredCards[currentCardType] = card;
		}
	}

	// Total value of highest value cards
	int total = 0;
	for (const auto& keyValuePair : scoredCards) {
		if (keyValuePair.second != nullptr) {
			total = total + keyValuePair.second->value();
		}
	}

	// Update the player score and return the value
	_score = total;
	
	return total;
}

// Prints the toString of each card currently in the play area
void Player::printPlayArea() const
{
	printf("%s's Play Area:\n", _name.c_str());
	for (std::shared_ptr<Card> card : playArea) {
		printf(" %s\n", card->toString().c_str());
	}
}
