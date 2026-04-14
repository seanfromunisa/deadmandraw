#pragma once
#include "Card.h"
class Hook :
    public Card
{
    enum CardType;

public:
    Hook();
    virtual std::string toString() override;
    virtual void play(Game& game, Player& player) override;
};