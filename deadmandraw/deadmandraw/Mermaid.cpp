#include "Mermaid.h"
#include "Player.h"
#include "Game.h"

Mermaid::Mermaid(int& value) :
	// Value is increased by 2
	_value{ value + 2 }
{
	CardType _type = CardType::Mermaid;
	std::string _stringType = "Mermaid";
}

// No effect. Ability is envoked on creation
void Mermaid::play(Game& game, Player& player)
{
	printf("No effect but Mermaids are worth more.\n");
}
