#pragma once
#include "Card.h"
class Hook :
    public Card
{
    enum CardType;

public:
    Hook();
    virtual std::string toString() const override;
    virtual void play(Game& game, Player& player) override;
    virtual void willAddToBank(Game& game, Player& player) override;
};