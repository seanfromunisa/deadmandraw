#include "Kraken.h"
#include "Player.h"
#include "Game.h"
#include <algorithm>

Kraken::Kraken(int& value)
{
	_value = value;
	_type = CardType::Kraken;
	_stringType = "Kraken";
}

// Draws and plays card 3 times
void Kraken::play(Game& game, Player& player)
{
	printf("Draw 3 Cards from the deck and play each:\n");
	for (int i = 0; i < std::min(3, static_cast<int>(game.cards.size())); i++) {
		bool playerNotBusted = true;
		if (playerNotBusted) {
			std::shared_ptr<Card> drawnCard = game.cards.back();
			game.cards.pop_back();
			playerNotBusted = player.playCard(drawnCard, game, player);
		}
	}
}