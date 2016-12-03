#pragma once

#include "Score.h"
#include <iostream>
#include <list>
#include "EnumOperations.h"

class Card
{
public:
	enum Value
	{
		Ace = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King
	};

	enum Suit
	{
		Spades,
		Clubs,
		Hearts,
		Diamonds
	};

	static NextEnum<Value, Value::Ace, Value::King> getNextValue;
	static NextEnum<Suit, Suit::Spades, Suit::Diamonds> getNextSuit;

	static PrevEnum<Value, Value::Ace, Value::King> getPrevValue;
	static PrevEnum<Suit, Suit::Spades, Suit::Diamonds> getPrevSuit;

	Card();
	Card(Value value, Suit suit);
	~Card();

	Score GetScore() const;
	Value GetValue() const;
	Suit GetSuit() const;

	bool operator==(const Card& other) const;

private:
	Value value;
	Suit suit;
	Score score;
};