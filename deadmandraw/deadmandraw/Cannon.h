#pragma once
#include "Card.h"
class Cannon :
    public Card
{
public:
    Cannon(int& value);
    void play(Game& game, Player& player) override;
};

