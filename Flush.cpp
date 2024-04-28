#include "Flush.h"

using namespace std;

bool Flush::isMatch(vector<Card> hand) const {
	bool suited{ true };
	auto card{ cbegin(hand) };

	const char suitCompare{ card->getSuit() };
	size_t count{ 0 };
	for (card; card != cend(hand); ++card) {
		if (card->getSuit() != suitCompare) {
			suited = false;
			break;
		}
	}
	return suited;
}