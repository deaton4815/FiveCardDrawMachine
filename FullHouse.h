#pragma once

#include "PokerHand.h"

class FullHouse : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const;
private:
	unsigned m_multiplier{ 9 };
	std::string m_name{ "Full House" };
};

