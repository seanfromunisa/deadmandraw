#pragma once
#include "Card.h"
class Mermaid :
    public Card
{
public:
    Mermaid(int& value);
    void play(Game& game, Player& player) override;
};