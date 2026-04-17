#include "Anchor.h"

Anchor::Anchor(int& value) :
	_value{ value }
{
	CardType _type = CardType::Anchor;
	std::string _stringType = "Anchor";
}

void Anchor::play(Game& game, Player& player)
{
	std::shared_ptr<Card> thisCard = player.playArea.back();
	player.playArea.pop_back();
	player.bankCards(game, player);
	player.playArea.push_back(thisCard);
}