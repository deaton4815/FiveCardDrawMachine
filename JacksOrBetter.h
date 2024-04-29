#pragma once

#include "PokerHand.h"

class JacksOrBetter : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const;

	unsigned getMultiplier() const;
	std::string getName() const;

private:
	unsigned m_multiplier{ 1 };
	std::string m_name{ "Jacks or Better" };
};

