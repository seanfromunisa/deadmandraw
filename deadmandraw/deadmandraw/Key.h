#pragma once
#include "Card.h"
class Key :
    public Card
{
    CardType _type;
    std::string _stringType;
    int _value;

public:
    Key(int& value);
    void play(Game& game, Player& player) override;
    void willAddToBank(Game& game, Player& player) override;
};