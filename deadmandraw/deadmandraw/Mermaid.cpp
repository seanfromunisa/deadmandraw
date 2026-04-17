#include "Mermaid.h"

Mermaid::Mermaid(int& value) :
	_value{ value + 2 }
{
	CardType _type = CardType::Mermaid;
	std::string _stringType = "Mermaid";
}

void Mermaid::play(Game& game, Player& player)
{
	printf{"No effect but Mermaids are worth more.\n"};
}

void Mermaid::willAddToBank(Game& game, Player& player)
{
}
