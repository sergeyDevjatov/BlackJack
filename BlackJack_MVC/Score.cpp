#include "Score.h"



Score::Score()
{
}

Score::Score(char score)
	:	mainScore(score),
		altScore(score)
{
}

template <class T>
inline T max(T lValue, T rValue)
{
	return lValue > rValue ? lValue : rValue;
}

template <class T>
inline T min(T lValue, T rValue)
{
	return lValue < rValue ? lValue : rValue;
}

Score::Score(char mainScore, char altScore)
	: mainScore(max(mainScore, altScore)),
	altScore(min(mainScore, altScore))
{
}

char Score::getMainScore() const
{
	return mainScore;
}

char Score::getAltScore() const
{
	return altScore;
}

bool Score::operator==(const Score& other) const
{
	return mainScore == other.mainScore
		&& altScore == other.altScore;
}

Score Score::operator+(const Score& other)
{
	Score result = *this;
	result += other;
	return result;
}

Score& Score::operator+=(const Score& other)
{
	mainScore += other.mainScore > 21
				  ? other.altScore : other.mainScore;
	altScore += other.altScore;
	if (mainScore > 21)
		mainScore = altScore;
	return *this;
}

Score Score::operator+(const Card::Value& value)
{
	Score result = *this;
	result += value;
	return result;
}

Score & Score::operator+=(const Card::Value& value)
{
	switch (value)
	{
		case Card::Value::Ace:
			return *this += Score(11, 1);
		case Card::Value::King:
		case Card::Value::Queen:
		case Card::Value::Jack:
			return *this += Score(10);
		default:
			return *this += Score(static_cast<char>(value));
	}
}
