#pragma once
#include <iostream>
#include "Player.h"
#include "Game.h"
class Card
{
public:
	enum CardType {
		Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken
	};
protected:
	CardType _type;
	std::string _stringType;
	int _value;

public:
	Card(CardType& type, int& value);
	virtual ~Card();
	std::string toString() const;
	const CardType& type() const;
	int value() const;
	// Look up how virtual functions or classes work
	virtual void play(Game &game, Player &player);
	Card& grabFromBank(Player &player);
	virtual void willAddToBank(Game &game, Player &player);
};