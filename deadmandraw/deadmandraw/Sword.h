#pragma once
#include "Card.h"
class Sword :
    public Card
{
    CardType _type;
    std::string _stringType;
    int _value;

public:
    Sword(int& value);
    virtual void play(Game& game, Player& player) override;
};