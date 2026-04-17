#include "Map.h"

Map::Map(int& value) :
	_value{ value }
{
	CardType _type = CardType::Map;
	std::string _stringType = "Map";
}

void Map::play(Game& game, Player& player)
{

}

void Map::willAddToBank(Game& game, Player& player)
{
}
