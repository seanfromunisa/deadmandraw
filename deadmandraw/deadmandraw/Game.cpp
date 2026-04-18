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
	PlayerPtr player1 = std::make_shared<Player>();
	PlayerPtr player2 = std::make_shared<Player>();
	int round = 0;
	int turn = 0;
	PlayerPtr currentPlayer = player1;
	PlayerPtr nonCurrentPlayer = player2;
	CardCollection cards = {};
	CardCollection discardPile = {};


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

	shuffleDeck(cards);

	printf("Starting Dead Man's Draw++!\n");
	while (cards.size() > 0 && turn < 20) {
		playerTurn();
	}
	gameEnd();
}

Game::~Game()
{
}

void Game::playerTurn()
{
	Game& deadMansDraw = *this;

	turn++;
	if (turn % 2 == 0) {
		round++;
	}

	if (currentPlayer == player1) {
		currentPlayer = player2;
		nonCurrentPlayer = player1;
	}
	else {
		currentPlayer = player1;
		nonCurrentPlayer = player2;
	}

	std::string drawCard = "y";
	//printf("--- Round %d, Turn %d ---\n%s's turn.\n", round, turn, currentPlayer->name().c_str());
	currentPlayer->displayPlayerBank();
	printf("%d", static_cast<int>(cards.size()));

	while (drawCard == "y") {
		std::shared_ptr<Card> drawnCard = cards.back();
		cards.pop_back();
		if (currentPlayer->playCard(*drawnCard, deadMansDraw, *currentPlayer)) {
			if (cards.size() > 0) {
				currentPlayer->printPlayArea();
				printf("\nDo you want to draw again? (y/n): ");
				scanf("%s", &drawCard);
				if (drawCard == "n") {
					currentPlayer->bankCards(deadMansDraw, *currentPlayer);
					currentPlayer->displayPlayerBank();
				}
			}
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