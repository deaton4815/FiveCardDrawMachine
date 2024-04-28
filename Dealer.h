#pragma once

#include <vector>
#include "CardDeck.h"
#include "Card.h"
#include "Hand.h"

class Dealer
{
public:

	void newGame();
	
	std::vector<char> getHandSuits() const;
	std::vector<unsigned> getHandRanks() const;

private:

	CardDeck m_deck;
	Hand m_hand;

	void dealHand();
};

