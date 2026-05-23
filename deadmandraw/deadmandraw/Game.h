#pragma once
#include <iostream>
#include <vector>

class Player;
class Card;

class Game
{
public:
	typedef std::vector<std::shared_ptr<Card>> CardCollection;

	Player* player1;
	Player* player2;
	int round;
	int turn;
	Player* currentPlayer;
	Player* nonCurrentPlayer;
	CardCollection cards;
	CardCollection discardPile;

	Game();
	~Game();
	void gameEnd();
	void shuffleDeck(CardCollection& cards);
	void playerTurn();
};