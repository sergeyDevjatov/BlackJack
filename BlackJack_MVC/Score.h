#pragma once

#include <iostream>
#include "Card.h"

class Score
{
public:
	Score();
	Score(char score);
	Score(char mainScore, char altScore);

	char getMainScore() const;
	char getAltScore() const;

	bool operator==(const Score& other) const;

	Score operator+(const Score& other);
	Score& operator+=(const Score& other);

	Score operator+(const Card::Value& value);
	Score& operator+=(const Card::Value& value);

private:
	char mainScore, altScore;

};
