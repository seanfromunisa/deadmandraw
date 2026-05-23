#pragma once
#include "Card.h"
class Kraken :
    public Card
{
public:
    Kraken(int& value);
    void play(Game& game, Player& player) override;
};