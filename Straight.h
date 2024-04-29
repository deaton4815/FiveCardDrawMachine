#pragma once

#include "PokerHand.h"
class Straight : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const ;

	unsigned getMultiplier() const;
	std::string getName() const;

private:
	unsigned m_multiplier{ 4 };
	std::string m_name{ "Straight" };
};

