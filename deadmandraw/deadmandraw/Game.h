#pragma once
#include <iostream>
#include "Player.h"
class Game
{
	int round;
	int turn;
	Player* current_player;

public:
	Game();
	~Game();
	void gameEnd();
	void shuffleDeck();
	bool playerTurn();
};

