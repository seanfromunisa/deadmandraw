#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Card.h"
class Game
{
	typedef std::vector<std::shared_ptr<Card>> CardCollection;

	Player* player1;
	Player* player2;
	int round;
	int turn;
	Player* currentPlayer;
	CardCollection cards;

public:
	Game();
	~Game();
	void gameEnd();
	void shuffleDeck(CardCollection& cards);
	bool playerTurn();
};