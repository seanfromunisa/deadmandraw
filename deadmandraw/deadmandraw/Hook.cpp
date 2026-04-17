#include "Hook.h"

Hook::Hook(int& value) :
	_value{ value }
{
	CardType _type = CardType::Hook;
	std::string _stringType = "Hook";
}

void Hook::play(Game& game, Player& player)
{
}

void Hook::willAddToBank(Game& game, Player& player)
{
}
