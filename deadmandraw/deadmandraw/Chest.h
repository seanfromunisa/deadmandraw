#pragma once
#include "Card.h"
class Chest :
    public Card
{
    enum CardType;

public:
    Chest();
    virtual std::string toString() override;
    virtual void play(Game& game, Player& player) override;
};