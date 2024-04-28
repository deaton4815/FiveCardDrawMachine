#include "FourOfAKind.h"

using namespace std;

bool FourOfAKind::isMatch(vector<Card> hand) const {
	vector<unsigned> ranks{ getSortedRanks(hand) };
	return hasNMatches(ranks, 4);
}