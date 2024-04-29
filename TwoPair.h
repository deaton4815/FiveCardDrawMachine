#pragma once

#include"PokerHand.h"

class TwoPair : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const;

	unsigned getMultiplier() const ;
	std::string getName() const;

private:
	unsigned m_multiplier{ 2 };
	std::string m_name{ "Two Pair" };
};

