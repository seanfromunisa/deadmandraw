#pragma once
#include <iostream>
#include "Player.h"
#include "Game.h"
class Card
{
	enum CardType;

public:
	virtual ~Card();
	virtual std::string toString() const;
	const CardType& type() const;
	virtual void play(Game &game, Player &player);
	virtual void willAddToBank(Game& game, Player& player);
};