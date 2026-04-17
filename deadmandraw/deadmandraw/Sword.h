#pragma once
#include "Card.h"
class Sword :
    public Card
{
    CardType _type;
    int _value;

public:
    Sword();
    virtual void play(Game& game, Player& player) override;
    virtual void willAddToBank(Game& game, Player& player) override;
};