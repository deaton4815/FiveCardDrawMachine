#pragma once

#include "PokerHand.h"

#include <algorithm>

class Straight : public PokerHand
{
public:
	bool isMatch(std::vector<Card>) const ;
private:
	std::vector<unsigned> getSortedRanks(std::vector<Card>) const;
};

