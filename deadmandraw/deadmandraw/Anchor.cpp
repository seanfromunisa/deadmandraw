#include "Anchor.h"

Anchor::Anchor(int& value) :
	_value{ value }
{
	CardType _type = CardType::Anchor;
	std::string _stringType = "Anchor";
}

void Anchor::play(Game& game, Player& player)
{
}

void Anchor::willAddToBank(Game& game, Player& player)
{
}