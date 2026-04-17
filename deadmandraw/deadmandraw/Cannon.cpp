#include "Cannon.h"

Cannon::Cannon(int& value) :
	_value{ value }
{
	CardType _type = CardType::Cannon;
	std::string _stringType = "Cannon";
}

void Cannon::play(Game& game, Player& player)
{
}

void Cannon::willAddToBank(Game& game, Player& player)
{
}
