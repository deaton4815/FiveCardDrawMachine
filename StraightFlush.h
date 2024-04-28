#pragma once

#include "PokerHand.h"
#include "Straight.h"
#include "Flush.h"

class StraightFlush : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const;

private:

	Straight m_straight;
	Flush m_flush;

	unsigned m_multiplier{ 50 };
	std::string m_name{ "Straight Flush" };
};

