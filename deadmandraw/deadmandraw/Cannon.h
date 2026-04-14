#pragma once
#include "Card.h"
class Cannon :
    public Card
{
    enum CardType;

public:
    Cannon();
    virtual std::string toString() override;
    virtual void play(Game& game, Player& player) override;
};

