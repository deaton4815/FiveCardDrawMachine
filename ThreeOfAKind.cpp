#include "ThreeOfAKind.h"

using namespace std;

bool ThreeOfAKind::isMatch(vector<Card> hand) const {
	vector<unsigned> ranks{ getSortedRanks(hand) };
	return hasNMatches(ranks, 3);
}

unsigned ThreeOfAKind::getMultiplier() const { return m_multiplier; }
string ThreeOfAKind::getName() const { return m_name; }