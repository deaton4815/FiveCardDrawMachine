#pragma once
#include "PokerHand.h"

class Flush : public PokerHand
{

public:
	bool isMatch(std::vector<Card>) const;
};

