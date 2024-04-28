#pragma once
class Card
{

public:
	Card(const char, const unsigned);

	char getSuit() const;
	unsigned getRank() const;

private:
	char m_suit; 
	unsigned m_rank;
};

