#include "Kraken.h"

Kraken::Kraken(int& value) :
	_value{ value }
{
	CardType _type = CardType::Kraken;
	std::string _stringType = "Kraken";
}

void Kraken::play(Game& game, Player& player)
{
}

void Kraken::willAddToBank(Game& game, Player& player)
{
}
