#pragma once
#include "Card.h"
class Chest :
    public Card
{
    enum CardType;

public:
    Chest();
    virtual std::string toString() const override;
    virtual void play(Game& game, Player& player) override;
    virtual void willAddToBank(Game& game, Player& player) override;
};