#pragma once
#include "Card.h"
class Oracle :
    public Card
{
    enum CardType;

public:
    Oracle();
    virtual std::string toString() const override;
    virtual void play(Game& game, Player& player) override;
    virtual void willAddToBank(Game& game, Player& player) override;
};