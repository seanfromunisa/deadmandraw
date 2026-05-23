#pragma once
#include "Card.h"
class Anchor :
    public Card
{
public:
    Anchor(int& value);
    void play(Game& game, Player& player) override;
};