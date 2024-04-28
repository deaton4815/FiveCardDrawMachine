#include "Flush.h"

using namespace std;

bool Flush::isMatch(vector<Card> hand) const {
	vector<char> suits;
	suits.reserve(hand.size());
	for (auto card{ cbegin(hand) }; card != cend(hand); ++card) {
		suits.push_back(card->getSuit());
	}
	return hasNMatches(suits, 5);
}