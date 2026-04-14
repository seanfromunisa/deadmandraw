#pragma once
#include "Card.h"
class Map :
    public Card
{
    enum CardType;

public:
    Map();
    virtual std::string toString() override;
    virtual void play(Game& game, Player& player) override;
};