#include "Hook.h"
#include "Player.h"
#include "Game.h"

Hook::Hook(int& value) :
	_value{ value }
{
	_type = CardType::Hook;
	_stringType = "Hook";
}

// If there are cards in the current player's bank, choose one to play with grabFromBank()
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