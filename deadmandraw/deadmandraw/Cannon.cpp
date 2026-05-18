#include "Cannon.h"
#include "Player.h"
#include "Game.h"

Cannon::Cannon(int& value) :
	_value{ value }
{
	_type = CardType::Cannon;
	_stringType = "Cannon";
}

// If there are cards in the opponent's bank, choose one to discard with grabFromBank()
void Cannon::play(Game& game, Player& player)
{
	if (game.nonCurrentPlayer->playerBank.empty()) {
		printf("No cards in other player's Bank. Play continues.\n");
	}
	else {
		printf("Steal the top card of any suit from the other player's Bank into your Play Area:\n");
		game.discardPile.push_back(&grabFromBank(*game.nonCurrentPlayer));
	}
}