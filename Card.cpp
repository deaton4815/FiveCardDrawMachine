#include "Card.h"

Card::Card(char suit, unsigned rank)
	: m_suit(suit)
	, m_rank(rank)
{}

char Card::getSuit() const { return m_suit; }
unsigned Card::getRank() const { return m_rank; }