#include "Anchor.h"
#include "Player.h"
#include "Game.h"

Anchor::Anchor(int& value)
{
	_value = value;
	_type = CardType::Anchor;
	_stringType = "Anchor";
}

// Removes itself from the play area, banks all cards in the play area, and then adds itself back
void Anchor::play(Game& game, Player& player)
{
	printf("Any existing cards in the play area are banked.\n");
	std::shared_ptr<Card> thisCard = player.playArea.back();
	player.playArea.pop_back();
	player.bankCards(game, player);
	player.playArea.push_back(thisCard);
}