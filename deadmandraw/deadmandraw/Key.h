#pragma once
#include "Card.h"
class Key :
    public Card
{
    enum CardType;

public:
    Key();
    virtual std::string toString() override;
    virtual void play(Game& game, Player& player) override;
};