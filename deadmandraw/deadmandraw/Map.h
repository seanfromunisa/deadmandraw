#pragma once
#include "Card.h"
class Map :
    public Card
{
public:
    Map(int& value);
    void play(Game& game, Player& player) override;
};