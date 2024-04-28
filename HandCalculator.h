#pragma once

#include <vector>
#include <array>

#include "Card.h"

#include "PokerHand.h"
#include "RoyalFlush.h"
#include "StraightFlush.h"
#include "FourOfAKind.h"
#include "FullHouse.h"
#include "Flush.h"
#include "Straight.h"
#include "ThreeOfAKind.h"
#include "TwoPair.h"
#include "JacksOrBetter.h"

class HandCalculator
{
public:
	void calculateHand(std::vector<Card>);

	unsigned getMultiplier();
	std::string getHandName();

private:
	RoyalFlush m_royalFlush;
	StraightFlush m_straightFlush;
	FourOfAKind m_fourOfAKind;
	FullHouse m_fullHouse;
	Flush m_flush;
	Straight m_straight;
	ThreeOfAKind m_threeOfAKind;
	TwoPair m_twoPair;
	JacksOrBetter m_jacksOrBetter;

	unsigned m_multiplier{ 0 };
	std::string m_name{ "" };
};

