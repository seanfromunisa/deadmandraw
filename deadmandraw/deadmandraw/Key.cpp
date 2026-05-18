#include "Key.h"
#include "Player.h"
#include "Game.h"
#include <algorithm>

Key::Key(int& value) :
	_value{ value }
{
	_type = CardType::Key;
	_stringType = "Key";
}

// No play effect. Ability relies on overwriting willAddToBank
void Key::play(Game& game, Player& player)
{
	printf("No immediate effect. If banked with a Chest, draw as many bonus cards from the Discard pile as you moved into your Bank.\n");
}

// When banked, ability will activate: Adding as many cards to bank from discard pile as banked from play area
void Key::willAddToBank(Game& game, Player& player)
{
	// Check for Chest in playArea
	for (Card card : player.playArea) {
		if (card.type() == CardType::Chest) {

			// If there are no cards in discard pile, bank nothing
			if (game.discardPile.empty()) {
				printf("Chest and Key activated. There are no cards in the Discard pile. Play continues.\n");
			}

			// If there are, bank as many as exist in play area, printing toString() of each
			else {
				printf("Chest and Key activated. Added ");

				// Will only add up to as many as exist in the discard pile
				for (int i = 0; i < std::min(static_cast<int>(game.discardPile.size()), static_cast<int>(player.playArea.size())); i++) {
					Card drawnCard = *game.discardPile.back();
					game.discardPile.pop_back();
					player.playerBank.push_back(drawnCard);
					printf("%s, ", drawnCard.toString().c_str());
				}
				printf("to your bank.");
			}
		}
	}
}
