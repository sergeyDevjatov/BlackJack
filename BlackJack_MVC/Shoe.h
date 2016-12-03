#pragma once

#include "Deck.h"
#include <iostream>
#include <vector>

using std::vector;

class Shoe
{
public:
	Shoe();
	~Shoe();

	Card Pop();
	int GetSummaryCount() const;
	vector<int> GetSeparatelyCounts() const;

private:
	enum { CountOfDecksInShoe = 4 };
	vector<Deck> decks { CountOfDecksInShoe };
	int summaryCount = CountOfDecksInShoe * Deck::DefaultCountOfCardsInDeck;

};
