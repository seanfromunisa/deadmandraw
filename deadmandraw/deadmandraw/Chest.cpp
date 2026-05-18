#include "Chest.h"
#include "Player.h"
#include "Game.h"

Chest::Chest(int& value) :
	_value{ value }
{
	_type = CardType::Chest;
	_stringType = "Chest";
}

// No effect. Activates Key ability
void Chest::play(Game& game, Player& player)
{
	printf("No immediate effect. If banked with a Key, draw as many bonus cards from the Discard pile as you moved into your Bank.\n");
}