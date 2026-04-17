#pragma once
#include "Card.h"
class Map :
    public Card
{
    CardType _type;
    std::string _stringType;
    int _value;

public:
    Map(int& value);
    virtual void play(Game& game, Player& player) override;
};