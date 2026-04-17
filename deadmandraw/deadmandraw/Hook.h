#pragma once
#include "Card.h"
class Hook :
    public Card
{
    CardType _type;
    std::string _stringType;
    int _value;

public:
    Hook(int& value);
    virtual void play(Game& game, Player& player) override;
};