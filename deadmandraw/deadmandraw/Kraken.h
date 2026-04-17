#pragma once
#include "Card.h"
class Kraken :
    public Card
{
    CardType _type;
    std::string _stringType;
    int _value;

public:
    Kraken(int& value);
    virtual void play(Game& game, Player& player) override;
};