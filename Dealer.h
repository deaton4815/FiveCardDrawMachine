#pragma once

#include <vector>
#include "CardDeck.h"
#include "Card.h"
#include "Hand.h"
#include "PayService.h"
#include "HandCalculator.h"

class Dealer
{
public:

	bool setWager(unsigned);
	void addFunds(unsigned);
	unsigned cashOut();

	void newHand();
	void setFinalHand(std::vector<unsigned>);
	void resetHand();
	
	std::size_t getHandSize() const;
	std::vector<char> getHandSuits() const;
	std::vector<unsigned> getHandRanks() const;

	unsigned getWagerAmount() const;
	unsigned getFunds() const;

	unsigned getPayout() const;
	std::string getHandName() const;

private:

	CardDeck m_deck;
	Hand m_hand;
	PayService m_payService;
	HandCalculator m_calculator;

	bool m_firstHand{ true };

	void dealHand();
	void executeKeepers(std::vector<unsigned>);
	void calculateHand();

	unsigned getMultiplier() const;
};

