#include "Key.h"

Key::Key(int& value) :
	_value{ value }
{
	CardType _type = CardType::Key;
	std::string _stringType = "Key";
}

void Key::play(Game& game, Player& player)
{
}

void Key::willAddToBank(Game& game, Player& player)
{
}
