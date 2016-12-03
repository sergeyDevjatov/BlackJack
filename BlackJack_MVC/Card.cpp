#include "Card.h"

Card::Card()
{
	value = Ace;
	suit = Spades;
}

Card::Card(Value value, Suit suit)
	: value(value), suit(suit)
{
	switch (value)
	{
		case Ace:
			score = Score(11, 1);
			break;
		case Ten:
		case Jack:
		case Queen:
		case King:
			score = Score(10);
			break;
		default:
			score = Score(value);
	}
}

Card::~Card()
{
}

Score Card::GetScore() const
{
	return value;
}

Card::Value Card::GetValue() const
{
	return value;
}

Card::Suit Card::GetSuit() const
{
	return suit;
}

bool Card::operator==(const Card & other) const
{
	return value == other.value && suit == other.suit;
}