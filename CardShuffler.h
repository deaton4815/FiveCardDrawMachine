#pragma once

#include <random>
#include <algorithm>

#include "Card.h"

class CardShuffler
{
public:

	CardShuffler();
	std::vector<Card> shuffleCards(std::vector<Card>);

private:

	std::default_random_engine m_shuffler;
	void setShuffler();
};