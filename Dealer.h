#pragma once

#include <vector>
#include "CardDeck.h"
#include "Card.h"
#include "Hand.h"

class Dealer
{
public:

	void dealHand();

private:

	CardDeck m_deck;
	Hand m_hand;
};

