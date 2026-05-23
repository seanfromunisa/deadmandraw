#pragma once
#include "Card.h"
class Sword :
    public Card
{
public:
    Sword(int& value);
    void play(Game& game, Player& player) override;
};