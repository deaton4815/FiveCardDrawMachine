#pragma once

#include "PokerHand.h"
class Straight : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const ;
};

