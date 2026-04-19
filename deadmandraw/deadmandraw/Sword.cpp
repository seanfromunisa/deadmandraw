#include "Sword.h"
#include "Player.h"
#include "Game.h"

Sword::Sword(int& value) :
	_value{ value }
{
	CardType _type = CardType::Sword;
	std::string _stringType = "Sword";
}

// If there are cards in the opponent's bank, choose one to play with grabFromBank()
void Sword::play(Game& game, Player& player)
{
	if (game.nonCurrentPlayer->playerBank.empty()) {
		printf("No cards in other player's Bank. Play continues.\n");
	}
	else {
		printf("Steal the top card of any suit from the other player's Bank into your Play Area: \n");
		player.playCard(grabFromBank(*game.nonCurrentPlayer), game, player);
	}
}