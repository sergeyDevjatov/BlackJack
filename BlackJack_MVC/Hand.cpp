#include "Hand.h"

Hand::Hand()
{
}

Hand::Hand(Card a, Card b)
{
	Push(a);
	Push(b);
}

Hand::~Hand()
{
}

Score Hand::GetScore() const
{
	return score;
}

int Hand::GetCount() const
{
	return cards.size();
}

bool Hand::IsSplitable() const
{
	if (cards.size() > 2)
	{
		auto it = cards.rbegin();
		return *it == *(++it);
	}
	return false;
}

vector<Card>::const_iterator Hand::cbegin() const
{
	return cards.cbegin();
}

vector<Card>::const_iterator Hand::cend() const
{
	return cards.cend();
}

void Hand::Push(Card card)
{
	cards.push_back(card);
	score += card.GetValue();
	if (score.getAltScore() > 21)
		throw BustException();
}

Card Hand::Pop()
{
	Card gotCard = cards.back();
	cards.pop_back();
	return gotCard;
}
