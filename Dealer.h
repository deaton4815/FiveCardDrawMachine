#pragma once

#include <vector>
#include "CardDeck.h"
#include "Card.h"
#include "Hand.h"
#include "PayService.h"

class Dealer
{
public:

	void newGame();
	void executeKeeperSelection(std::vector<unsigned>);
	
	std::size_t getHandSize() const;
	std::vector<char> getHandSuits() const;
	std::vector<unsigned> getHandRanks() const;

private:

	CardDeck m_deck;
	Hand m_hand;
	PayService m_payService;

	bool m_firstHand{ true };

	void dealHand();
};

