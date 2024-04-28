#pragma once

#include "Card.h"
#include <vector>
class PokerHand
{
public:

	virtual bool isMatch(std::vector<Card>) const = 0;
};

