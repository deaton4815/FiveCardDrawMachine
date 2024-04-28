#pragma once

#include <array>
#include <vector>
#include<random>

#include "Card.h"
#include "CardShuffler.h"


#include<iostream>//FOR TESTING

class CardDeck
{

public:

	CardDeck();

	std::vector<Card> getCards(const size_t);
	void addCards(const std::vector<Card>&);
	void shuffleDeck();

	//TEST FUNCTION
	void printDeck();

private:

	const std::array<char, 4> m_suits{'H', 'C', 'D', 'S'};
	const std::array<unsigned, 13> m_ranks{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	std::vector <Card> m_deck;

	CardShuffler m_shuffler;

	void initializeDeck();
	Card newCard(const char, const unsigned) const;

};

