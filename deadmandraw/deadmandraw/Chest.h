#pragma once
#include "Card.h"
class Chest :
    public Card
{
    CardType _type;
    std::string _stringType;
    int _value;

public:
    Chest(int& value);
    void play(Game& game, Player& player) override;
};