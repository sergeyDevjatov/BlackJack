#pragma once

#include "Card.h"
#include <iostream>
#include <vector>

using std::vector;

class Deck
{
public:
	enum { DefaultCountOfCardsInDeck = 52 };
	Deck();

	Card Pop();
	Card Peek() const;
	void Shuffle();
	int GetCount() const;

private:
	vector<Card> cards = vector<Card>(DefaultCountOfCardsInDeck);
};
