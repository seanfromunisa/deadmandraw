#pragma once
#include "Card.h"
class Cannon :
    public Card
{
    CardType _type;
    std::string _stringType;
    int _value;

public:
    Cannon(int& value);
    virtual void play(Game& game, Player& player) override;
};

