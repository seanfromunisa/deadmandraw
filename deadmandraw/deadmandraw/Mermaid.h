#pragma once
#include "Card.h"
class Mermaid :
    public Card
{
    CardType _type;
    std::string _stringType;
    int _value;

public:
    Mermaid(int& value);
    virtual void play(Game& game, Player& player) override;
};