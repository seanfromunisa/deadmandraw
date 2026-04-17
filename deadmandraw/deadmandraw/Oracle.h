#pragma once
#include "Card.h"
class Oracle :
    public Card
{
    CardType _type;
    std::string _stringType;
    int _value;

public:
    Oracle(int& value);
    virtual void play(Game& game, Player& player) override;
};