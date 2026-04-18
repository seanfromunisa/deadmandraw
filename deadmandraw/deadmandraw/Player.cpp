#include "Player.h"
#include "Card.h"
#include "Game.h"
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

bool Player::playCard(Card& card, Game& game, Player& player)
{
	printf("%s draws a %s", _name, card.toString());
	bool notBust = true;
	for (std::shared_ptr<Card> playedCard : playArea) {
		if (playedCard->type() == card.type()) {
			notBust = false;
		}
	}
	if (notBust == false) {
		printf("BUST! %s loses all cards in play area.", _name);
		for (std::shared_ptr<Card> disCards : playArea) {
			game.discardPile.push_back(disCards);
		}
		playArea.clear();
	}
	else {
		card.play(game, player);
	}
	return notBust;
}

void Player::bankCards(Game& game, Player& player)
{
	for (std::shared_ptr<Card> card : playArea) {
		card->willAddToBank(game, player);
	}
	playArea.clear();
}

void Player::displayPlayerBank() const
{
	printf("print player bank lol");
}

int Player::calculateScore()
{
	std::map<Card::CardType, std::shared_ptr<Card>> scoredCards;
	for (std::shared_ptr<Card> card : playerBank) {
		Card::CardType currentCardType = card->type();
		if (scoredCards[currentCardType]->value() < card->value()) {
			scoredCards[currentCardType] = card;
		}
	}

	int total = 0;
	for (const auto& keyValuePair : scoredCards) {
		total = total + keyValuePair.second->value();
	}

	_score = total;
	
	return total;
}

void Player::printPlayArea() const
{
	printf("print play area lmfao");
}
