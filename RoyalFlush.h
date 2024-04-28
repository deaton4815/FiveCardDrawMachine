#pragma once

#include "PokerHand.h"
#include "StraightFlush.h"

class RoyalFlush : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const;
private:
	StraightFlush m_straightFlush;

	unsigned m_multiplier{ 250 };
	std::string m_name{ "Royal Flush" };
};

