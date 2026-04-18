#pragma once
#include <iostream>

class Player;
class Game;

class Card
{
public:
	enum CardType {
		None, Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken
	};
protected:
	CardType _type = CardType::None;
	std::string _stringType;
	int _value = 0;

public:
	virtual ~Card();
	std::string toString() const;
	const CardType& type() const;
	int value() const;
	virtual void play(Game& game, Player& player);
	Card& grabFromBank(Player &player);
	virtual void willAddToBank(Game& game, Player& player);
};