#pragma once
#include <string>
#include "Player.h"
#include "Game.h"
class Card
{
	enum CardType;

public:
	virtual ~Card();
	virtual std::string toString();
	const CardType& type() const;
	virtual void play(Game &game, Player &player);
	virtual void willAddToBank(Game& game, Player& player);
};