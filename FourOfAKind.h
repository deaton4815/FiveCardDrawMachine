#pragma once

#include "PokerHand.h"

class FourOfAKind : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const;

	unsigned getMultiplier() const;
	std::string getName() const;

private:
	unsigned m_multiplier{ 25 };
	std::string m_name{ "Four of a Kind" };
};

