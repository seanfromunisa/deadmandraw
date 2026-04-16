#include "Card.h"
#include <string>

Card::Card(CardType& type, int& value) :
	_type{ type },
	_value{ value }
{
	std::string typeStrings[] = { "Cannon", "Chest", "Key", "Anchor", "Sword", "Hook", "Oracle", "Map", "Mermaid", "Kraken" };
	std::string _stringType = typeStrings[_type];
}

Card::~Card()
{
}

std::string Card::toString() const
{
	return _stringType + "(" + std::to_string(_value) + ")";
}

const Card::CardType& Card::type() const
{
	return _type;
}

int Card::value() const
{
	return _value;
}

bool Card::play(Game& game)
{
	std::shared_ptr<Card> drawnCard = game.cards[static_cast<int>(game.cards.size()) - 1];
	game.cards.pop_back();
	if (game.currentPlayer->playCard(drawnCard)) {
		effect(game);
		return true;
	}
	else {
		return false;
	};
}
