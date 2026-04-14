#pragma once
#include "Card.h"
class Anchor :
    public Card
{
    enum CardType;

public:
    Anchor();
    virtual std::string toString() override;
    virtual void play(Game& game, Player& player) override;
};