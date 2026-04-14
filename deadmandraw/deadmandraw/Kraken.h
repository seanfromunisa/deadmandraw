#pragma once
#include "Card.h"
class Kraken :
    public Card
{
    enum CardType;

public:
    Kraken();
    virtual std::string toString() override;
    virtual void play(Game& game, Player& player) override;
};