#pragma once
#include "PokerHand.h"

class Flush : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const;

	unsigned getMultiplier() const;
	std::string getName() const;

private:
	unsigned m_multiplier{ 6 };
	std::string m_name{ "Flush" };
};

