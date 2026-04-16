#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Card.h"
class Game
{
public:
	typedef std::shared_ptr<Player> PlayerPtr;
	typedef std::vector<std::shared_ptr<Card>> CardCollection;

	PlayerPtr player1;
	PlayerPtr player2;
	int round;
	int turn;
	PlayerPtr currentPlayer;
	CardCollection cards;
	CardCollection discardPile;

	Game();
	~Game();
	void gameEnd();
	void shuffleDeck(CardCollection& cards);
	void playerTurn();
};