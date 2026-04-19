#include "Key.h"
#include "Player.h"
#include "Game.h"
#include <algorithm>

Key::Key(int& value) :
	_value{ value }
{
	CardType _type = CardType::Key;
	std::string _stringType = "Key";
}

void Key::play(Game& game, Player& player)
{
	printf("No immediate effect. If banked with a Chest, draw as many bonus cards from the Discard pile as you moved into your Bank.\n");
}

void Key::willAddToBank(Game& game, Player& player)
{
	for (Card card : player.playArea) {
		if (card.type() == CardType::Chest) {
			if (game.discardPile.empty()) {
				printf("Chest and Key activated. There are no cards in the Discard pile. Play continues.\n");
			}
			else {
				printf("Chest and Key activated. Added ");
				for (int i = 0; i < std::min(static_cast<int>(game.discardPile.size()), static_cast<int>(player.playArea.size())); i++) {
					Card drawnCard = *game.discardPile.back();
					game.discardPile.pop_back();
					player.playerBank.push_back(drawnCard);
					printf("%s, ", drawnCard.toString());
				}
				printf("to your bank.");
			}
		}
	}
}
