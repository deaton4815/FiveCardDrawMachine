#pragma once

#include <vector>
#include "Card.h"

class Hand
{
public:

	void newHand(const std::vector<Card>&);
	void setDiscards(const std::vector<unsigned>&);
	void replaceDiscards(const std::vector<Card>&);
	void resetHand();

	const std::size_t getHandSize() const;
	std::size_t	getDiscardCount() const;
	std::vector<Card> getAllCards() const;

private:

	const std::size_t m_handSize{ 5 };
	std::vector<Card> m_hand;

	std::vector<unsigned> m_discardIndices;
	std::vector<Card> m_discards;

	void setDiscardIndices(const std::vector<unsigned>&);
	void setDiscardedCards();

	bool isKeeper(const unsigned, const std::vector<unsigned>&) const;
};

