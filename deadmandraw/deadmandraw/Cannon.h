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
    void play(Game& game, Player& player) override;
};

