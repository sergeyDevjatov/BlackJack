#pragma once

#include "Card.h"
#include <vector>
#include <exception>

using std::vector;

class Hand
{
	vector<Card> cards;
	Score score;
	
public:
	Hand();
	Hand(Card a, Card b);
	~Hand();

	Score GetScore() const;
	int GetCount() const;

	bool IsSplitable() const;

	typedef vector<Card>::const_iterator const_iterator;
	const_iterator cbegin() const noexcept;
	const_iterator cend() const noexcept;

	void Push(Card card);
	Card Pop();
};

class BustException : public std::exception
{
public:
	const char* what() const noexcept
	{
		return "Bust.";
	}
};