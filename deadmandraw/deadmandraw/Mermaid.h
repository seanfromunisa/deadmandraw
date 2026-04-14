#pragma once
#include "Card.h"
class Mermaid :
    public Card
{
    enum CardType;

public:
    Mermaid();
    virtual std::string toString() override;
    virtual void play(Game& game, Player& player) override;
};