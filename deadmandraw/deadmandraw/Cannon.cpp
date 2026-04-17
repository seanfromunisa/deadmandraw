#include "Cannon.h"

Cannon::Cannon(int& value) :
	_value{ value }
{
	CardType _type = CardType::Cannon;
	std::string _stringType = "Cannon";
}

void Cannon::play(Game& game, Player& player)
{
	if (game.nonCurrentPlayer->playerBank.empty()) {
		printf("No cards in other player's Bank. Play continues.\n");
	}
	else {
		printf("Steal the top card of any suit from the other player's Bank into your Play Area:\n");
		game.discardPile.push_back(std::make_shared<Card>(grabFromBank(*game.nonCurrentPlayer)));
	}
}