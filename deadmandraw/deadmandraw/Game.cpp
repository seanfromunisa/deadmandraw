#include "Game.h"
#include <algorithm>
#include <random>
#include <memory>
#include "Card.h"

Game::Game()
{
	Player* player1 = new Player();
	Player* player2 = new Player();
	int round = 0;
	int turn = 0;
	Player* currentPlayer = player1;
	CardCollection cards = {};

	std::vector<Card::CardType> suits = {
		Card::Cannon, Card::Chest, Card::Key, Card::Anchor, Card::Sword, Card::Hook,
		Card::Oracle, Card::Map, Card::Mermaid, Card::Kraken};
	for ( Card::CardType& suit : suits ) {
		for (int value = 2; value < 7; value++) {
			int finalValue = value;
			if (suit == Card::Mermaid) {
				finalValue + 2;
			}
			cards.push_back(std::make_shared<Card>(suit, finalValue));
		}
	}
	shuffleDeck(cards);

	printf("Starting Dead Man's Draw++!\n");
	//while (game still going) {
		playerTurn();
	//}
	gameEnd();
}

Game::~Game()
{
}

bool Game::playerTurn()
{
	turn++;
	if (turn % 2 == 0) {
		round++;
	}
	// switch currentPlayer
	std::string drawCard = "y";
	printf("--- Round %d, Turn %d ---\n%s's turn.\n", round, turn, currentPlayer->name().c_str());
	currentPlayer->displayPlayerBank();

	while (drawCard == "y") {
		if (cards.size() > 1) {
			
			if (currentPlayer->playCard(cards[0])) {
				currentPlayer->printPlayArea();
				printf("\nDo you want to draw again? (y/n): ");
				//scan for input
				if (drawCard == "n") {
					// for each card in play area:
						// card->willAddToBank();
					currentPlayer->displayPlayerBank();
				}
			}
			else {
				drawCard = "n";
			}
		}
		else {

		}
	}

	//return (game still going);
}

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