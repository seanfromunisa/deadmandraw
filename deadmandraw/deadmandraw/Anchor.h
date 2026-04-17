#pragma once
#include "Card.h"
class Anchor :
    public Card
{
    CardType _type;
    std::string _stringType;
    int _value;

public:
    Anchor(int& value);
    void play(Game& game, Player& player) override;
};