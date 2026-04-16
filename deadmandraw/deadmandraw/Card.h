#pragma once
#include <iostream>
#include "Player.h"
#include "Game.h"
class Card
{
	enum CardType {
		Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken};
	CardType type;

public:
	virtual std::string toString() const
	const CardType& getType() const;
	virtual void play(Game &game, Player &player);
	virtual void willAddToBank(Game &game, Player &player);
};