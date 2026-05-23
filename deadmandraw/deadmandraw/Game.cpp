#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include "Player.h"
#include <algorithm>
#include <random>
#include <memory>
#include "Card.h"
#include "Anchor.h"
#include "Cannon.h"
#include "Chest.h"
#include "Hook.h"
#include "Key.h"
#include "Kraken.h"
#include "Map.h"
#include "Mermaid.h"
#include "Oracle.h"
#include "Sword.h"

Game::Game()
{
	// Initialising the Game variables
	player1 = new Player();
	player2 = new Player();
	round = 0;
	turn = 0;
	currentPlayer = player1;
	nonCurrentPlayer = player2;
	cards;
	discardPile;

	// Cards of each suit with values 2-7 are added to the deck
	for (int i = 2; i < 8; i++) {
		cards.push_back(std::make_shared<Anchor>(i));
		cards.push_back(std::make_shared<Cannon>(i));
		cards.push_back(std::make_shared<Chest>(i));
		cards.push_back(std::make_shared<Hook>(i));
		cards.push_back(std::make_shared<Key>(i));
		cards.push_back(std::make_shared<Kraken>(i));
		cards.push_back(std::make_shared<Map>(i));
		cards.push_back(std::make_shared<Mermaid>(i));
		cards.push_back(std::make_shared<Oracle>(i));
		cards.push_back(std::make_shared<Sword>(i));
	}

	// The deck is shuffled
	shuffleDeck(cards);

	//TESTING!!!!
	for (std::shared_ptr<Card> card : cards) {
		printf("%s", card->toString().c_str());
	}
	printf("%d", static_cast<int>(cards.size()));

	// The game loop starts, checking each turn for an empty deck or if 20 rounds have been played before ending
	printf("Starting Dead Man's Draw++!\n");
	while (cards.size() > 0 && turn < 20) {
		playerTurn();
	}
	gameEnd();
}

Game::~Game()
{
}

// Turn-based gameplay loop
void Game::playerTurn()
{
	// Game reference is created to be used in Card and Player functions
	Game& deadMansDraw = *this;

	// The turn counter is increased, and once both players have had a turn, the round counter is increased
	turn++;
	if (turn % 2 != 0) {
		round++;
	}

	// Switches the current and non-current player
	if (currentPlayer == player1) {
		currentPlayer = player2;
		nonCurrentPlayer = player1;
	}
	else {
		currentPlayer = player1;
		nonCurrentPlayer = player2;
	}

	// drawCard reflects the players choice to draw another card, repeating the "while" loop, though it will always draw at least once
	std::string drawCard = "y";

	// Display the turn and player information
	printf("--- Round %d, Turn %d ---\n%s's turn.\n", round, turn, currentPlayer->name().c_str());
	currentPlayer->displayPlayerBank();

	// Aforementioned card drawing loop
	while (drawCard == "y") {

		// A card is taken from the deck, to be placed in the play area with Player.playCard()
		std::shared_ptr<Card> drawnCard = cards.back();
		cards.pop_back();

		// playCard() will return whether the player busted before allowing them to draw again
		if (currentPlayer->playCard(drawnCard, deadMansDraw, *currentPlayer)) {
			if (cards.size() > 0) {
				currentPlayer->printPlayArea();
				printf("\nDo you want to draw again? (y/n): ");
				scanf("%s", drawCard);
				if (drawCard == "n") {
					
					// If the player chooses not to draw again, the played cards are added to their bank
					currentPlayer->bankCards(deadMansDraw, *currentPlayer);
					currentPlayer->displayPlayerBank();
				}
			}

			// If there are no more cards to draw, the draw loop and player turn will end
			else {
				printf("NO MORE CARDS! The deck is now empty.\n");
				drawCard = "n";
			}
		}
		else {
			drawCard = "n";
		}
	}
}

// Print player banks and then compare the player scores, announcing the winner
void Game::gameEnd()
{
	printf("--- Game Over ---");
	player1->displayPlayerBank();
	player2->displayPlayerBank();

	if (player1->score() > player2->score()) {
		printf("%s wins!", player1->name().c_str());
	}
	else if (player2->score() > player1->score()) {
		printf("%s wins!", player2->name().c_str());
	}
	else {
		printf("It's a draw!");
	}
}

void Game::shuffleDeck(CardCollection& cards)
{
	CardCollection shuffleDeck{ cards.begin(), cards.end() };
	std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
	std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
}