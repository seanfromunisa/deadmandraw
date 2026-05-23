#pragma once
#include "Card.h"
class Oracle :
    public Card
{
public:
    Oracle(int& value);
    void play(Game& game, Player& player) override;
};