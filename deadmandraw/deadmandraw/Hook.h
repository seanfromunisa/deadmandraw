#pragma once
#include "Card.h"
class Hook :
    public Card
{
public:
    Hook(int& value);
    void play(Game& game, Player& player) override;
};