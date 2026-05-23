#pragma once
#include "Card.h"
class Chest :
    public Card
{
public:
    Chest(int& value);
    void play(Game& game, Player& player) override;
};