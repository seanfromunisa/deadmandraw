#pragma once
#include "Card.h"
class Oracle :
    public Card
{
    enum CardType;

public:
    Oracle();
    virtual std::string toString() override;
    virtual void play(Game& game, Player& player) override;
};