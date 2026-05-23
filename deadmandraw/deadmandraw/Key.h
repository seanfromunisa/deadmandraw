#pragma once
#include "Card.h"
class Key :
    public Card
{
public:
    Key(int& value);
    void play(Game& game, Player& player) override;
    void willAddToBank(Game& game, Player& player) override;
};