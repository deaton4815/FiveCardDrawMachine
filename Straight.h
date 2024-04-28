#pragma once

#include "PokerHand.h"
class Straight : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const ;

private:
	unsigned m_multiplier{ 4 };
	std::string name{ "Straight" };
};

