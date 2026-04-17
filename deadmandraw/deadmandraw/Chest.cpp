#include "Chest.h"

Chest::Chest(int& value) :
	_value{ value }
{
	CardType _type = CardType::Chest;
	std::string _stringType = "Chest";
}

void Chest::play(Game& game, Player& player)
{
}

void Chest::willAddToBank(Game& game, Player& player)
{
}
