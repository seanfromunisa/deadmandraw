#include "Oracle.h"
#include "Player.h"
#include "Game.h"

Oracle::Oracle(int& value) :
	_value{ value }
{
	_type = CardType::Oracle;
	_stringType = "Oracle";
}

// Display the top card of the deck, if exists
void Oracle::play(Game& game, Player& player)
{
	if (game.cards.empty()) {
		printf("There are no more cards. Play continues.\n");
	}
	else {
		printf("The Oracle sees a %s\n", game.cards.back()->toString().c_str());
	}
}