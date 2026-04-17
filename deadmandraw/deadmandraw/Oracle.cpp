#include "Oracle.h"

Oracle::Oracle(int& value) :
	_value{ value }
{
	CardType _type = CardType::Oracle;
	std::string _stringType = "Oracle";
}

void Oracle::play(Game& game, Player& player)
{
	if (static_cast<int>(game.cards.size) = 0) {
		printf("There are no more cards. Play continues.\n")
	}
	else {
		printf("The Oracle sees a %s\n", game.cards.back()->toString());
	}
}

void Oracle::willAddToBank(Game& game, Player& player)
{
}
