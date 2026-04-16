#include "Game.h"

Game::Game()
{
	Player* player1 = new Player();
	Player* player2 = new Player();
	int round = 0;
	int turn = 0;
	Player* currentPlayer = player1;

	// set up cards
	shuffleDeck(cards);

	printf("Starting Dead Man's Draw++!\n");
	while (game still going) {
		playerTurn();
	}
	gameEnd();
}

bool Game::playerTurn()
{
	turn++;
	if (turn % 2 == 0) {
		round++;
	}
	// switch currentPlayer
	std::string drawCard = "y";
	printf("--- Round %d, Turn %d ---\n%s's turn.\n", round, turn, currentPlayer->playerName().c_str());
	currentPlayer->displayPlayerBank();

	while (drawCard == "y") {
		if (currentPlayer->playCard()) {
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

	//return (game still going);
}

void Game::gameEnd()
{
	printf("--- Game Over ---");
	player1->displayPlayerBank();
	player2->displayPlayerBank();

	if (player1->playerScore() > player2->playerScore()) {
		printf("%s wins!", player1->playerName().c_str());
	}
	else if (player2->playerScore() > player1->playerScore()) {
		printf("%s wins!", player2->playerName().c_str());
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