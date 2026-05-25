#include "Hook.h"
#include "Player.h"
#include "Game.h"

Hook::Hook(int& value)
{
	_value = value;
	_type = CardType::Hook;
	_stringType = "Hook";
}

// If there are cards in the current player's bank, choose one to play with grabFromBank()
void Hook::play(Game& game, Player& player)
{
	if (player.playerBank.empty()) {
		printf(" No cards in your Bank. Play continues.\n");
	}
	else {
		printf(" Select a highest-value card from any of the suits in your Bank: \n");
		player.playCard(grabFromBank(player), game, player);
	}
}