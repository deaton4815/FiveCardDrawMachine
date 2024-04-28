#pragma once

#include "Card.h"
#include <vector>
#include <algorithm>
#include <string>

class PokerHand
{
public:
	virtual bool isMatch(std::vector<Card>) const = 0;
	unsigned getMultiplier() const;
	std::string getName() const;

protected:
	std::vector<unsigned> getSortedRanks(std::vector<Card>) const;
	template<typename T> bool hasNMatches(std::vector<T>, unsigned) const;

private:
	unsigned m_multiplier;
	std::string m_name;
};

