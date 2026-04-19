#include "Kraken.h"
#include "Player.h"
#include "Game.h"
#include <algorithm>

Kraken::Kraken(int& value) :
	_value{ value }
{
	CardType _type = CardType::Kraken;
	std::string _stringType = "Kraken";
}

// Draws and plays card 3 times
void Kraken::play(Game& game, Player& player)
{
	printf("Draw 3 Cards from the deck and play each:\n");
	for (int i = 0; i < std::min(3, static_cast<int>(game.cards.size())); i++) {
		Card drawnCard = *game.cards.back();
		game.cards.pop_back(); 
		player.playCard(drawnCard, game, player);
	}
}