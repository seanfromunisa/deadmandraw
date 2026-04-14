#pragma once
#include "Card.h"
class Sword :
    public Card
{
    enum CardType;

public:
    Sword();
    virtual std::string toString() const override;
    virtual void play(Game& game, Player& player) override;
};