#include "Deck.h"
#include <algorithm>
#include <random>
#include <chrono>

using std::shuffle;
using std::default_random_engine;
using std::chrono::system_clock;

void Deck::Shuffle()
{
	unsigned seed = system_clock::now().time_since_epoch().count();
	shuffle(cards.begin(), cards.end(), default_random_engine(seed));
}

Deck::Deck()
{
	Card::Value j = Card::Ace;
	Card::Suit k = Card::Spades;
	for (auto it = cards.begin(); it != cards.end(); ++it)
	{
		*it = Card(j, k);
		j = Card::getNextValue(j);
		k = Card::getNextSuit(k);
	}
	Shuffle();
}

Card Deck::Pop()
{
	Card lastCard = cards.back();
	cards.pop_back();
	return lastCard;
}

Card Deck::Peek() const
{
	return cards.back();
}

int Deck::GetCount() const
{
	return cards.size();
}