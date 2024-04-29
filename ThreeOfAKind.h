#pragma once

#include "PokerHand.h"

class ThreeOfAKind : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const;

	unsigned getMultiplier() const;
	std::string getName() const;

private:
	unsigned m_multiplier{ 3 };
	std::string m_name{ "Three of a Kind" };
};