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
	printf(" Draw 3 Cards from the deck and play each:\n");

	// Boolean playerNotBusted checks that each card drawn does not bust before drawing the next
	bool playerNotBusted = true;
	for (int i = 0; i < std::min(3, static_cast<int>(game.cards.size())); i++) {
		if (playerNotBusted) {
			std::shared_ptr<Card> drawnCard = game.cards.back();
			game.cards.pop_back();
			playerNotBusted = player.playCard(drawnCard, game, player);

			// If the player has busted, set notBust in Player to false, which will return to Game, resulting in the Game recognising a bust
			if (!playerNotBusted) {
				player.setNotBust(false);
			}
		}
	}
}