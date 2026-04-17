#include "Hook.h"

Hook::Hook(int& value) :
	_value{ value }
{
	CardType _type = CardType::Hook;
	std::string _stringType = "Hook";
}

void Hook::play(Game& game, Player& player)
{
	if (game.nonCurrentPlayer->playerBank.empty()) {
		printf("No cards in other player's Bank. Play continues.\n");
	}
	else {
		printf("Steal the top card of any suit from the other player's Bank into your Play Area: \n");
		player.playCard(grabFromBank(player), game, player);
	}
}