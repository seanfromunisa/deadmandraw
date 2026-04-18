#define _CRT_SECURE_NO_WARNINGS
#include "Map.h"
#include "Player.h"
#include "Game.h"
#include <string>
#include <vector>

Map::Map(int& value) :
	_value{ value }
{
	CardType _type = CardType::Map;
	std::string _stringType = "Map";
}

void Map::play(Game& game, Player& player)
{
	if (game.discardPile.empty()) {
		printf("No cards in Discard pile.Play continues.\n");
	}
	else {
		printf("Draw 3 cards from the discard and pick one to add to the play area: \n");
		std::vector<std::shared_ptr<Card>> mapCards;
		for (int i = 0; i < std::min(3, static_cast<int>(game.discardPile.size())); i++) {
			std::shared_ptr<Card> drawnCard = game.discardPile.back();
			game.discardPile.pop_back();
			mapCards.push_back(drawnCard);
		}
		for (int i = 0; i < static_cast<int>(mapCards.size()); i++) {
			printf("(%d) %s\n", (i + 1), mapCards[i]->toString());
		}

		int cardPick = 0;
		printf("Which card do you pick? ");
		scanf("%d", &cardPick);

		std::shared_ptr<Card> pickedCard = mapCards[cardPick];
		for (int i = 0; i < static_cast<int>(mapCards.size()); i++) {
			if (i != cardPick) {
				game.discardPile.push_back(mapCards[i]);
			}
		}
		player.playCard(*pickedCard, game, player);
	}
}
