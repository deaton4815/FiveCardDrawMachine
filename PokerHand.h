#pragma once

#include "Card.h"
#include <vector>
#include <algorithm>

class PokerHand
{
public:
	virtual bool isMatch(std::vector<Card>) const = 0;
protected:
	std::vector<unsigned> getSortedRanks(std::vector<Card>) const;
};

