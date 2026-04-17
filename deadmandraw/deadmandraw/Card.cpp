#include "Card.h"
#include <string>
#include <map>

Card::~Card()
{
}

std::string Card::toString() const
{
	return _stringType + "(" + std::to_string(_value) + ")";
}

const Card::CardType& Card::type() const
{
	return _type;
}

int Card::value() const
{
	return _value;
}

Card& Card::grabFromBank(Player& player)
{
	std::map<CardType, std::shared_ptr<Card>> availableCards;
	for (std::shared_ptr<Card> card : player.playerBank) {
		CardType currentCardType = card->type();
		if (availableCards[currentCardType]->value() < card->value()) {
			availableCards[currentCardType] = card;
		}
	}

	std::vector<std::shared_ptr<Card>> finalCards = {};
	for (const auto& keyValuePair : availableCards) {
		finalCards.push_back(keyValuePair.second);
	}

	for (int i = 0; i < static_cast<int>(finalCards.size()); i++) {
		printf("(%d) %s\n" (i + 1), finalCards[i]->toString());
	}

	int cardPick;
	printf("Which card do you pick? ");
	scanf("%d", cardPick);

	return finalCards[cardPick - 1];
}