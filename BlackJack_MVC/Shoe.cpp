#include "Shoe.h"
#include <iostream>

inline int randInt(int from, int to)
{
	if (from > to)
		std::swap(from, to);
	return rand() % (to - from) + from;
}

Shoe::Shoe()
{
}


Shoe::~Shoe()
{

}

Card Shoe::Pop()
{
	int deckToPop = randInt(0, decks.size());
	summaryCount--;
	return decks[deckToPop].Pop();
}

int Shoe :: GetSummaryCount() const
{
	return summaryCount;
}

vector<int> Shoe::GetSeparatelyCounts() const
{
	std::cout << 1;
	vector<int> counts;
	for (auto& deck : decks)
		counts.push_back(deck.GetCount());
	return counts;
}

