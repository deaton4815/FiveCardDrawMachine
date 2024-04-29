#pragma once

#include "Card.h"
#include <vector>
#include <algorithm>
#include <string>

class PokerHand
{
public:
	virtual bool isMatch(std::vector<Card>) const = 0;
	virtual unsigned getMultiplier() const = 0;
	virtual std::string getName() const = 0;

protected:
	std::vector<unsigned> getSortedRanks(std::vector<Card>) const;
	bool hasNMatches(std::vector<unsigned>, unsigned) const;
};

