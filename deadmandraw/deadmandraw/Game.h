#pragma once
class Game
{
	int round;
	int turn;
	Player current_player;

public:
	Game();
	~Game();
	void gameEnd();
	CardCollection shuffleDeck();
	void playerTurn();
};

