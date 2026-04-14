#pragma once
#include <iostream>
#include "Player.h"
class Game
{
	Player* player1;
	Player* player2;
	int round;
	int turn;
	Player* current_player;

public:
	Game();
	~Game();
	void gameEnd();
	void shuffleDeck(CardCollection& cards);
	bool playerTurn();
};

