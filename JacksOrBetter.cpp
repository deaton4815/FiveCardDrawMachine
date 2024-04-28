#include "JacksOrBetter.h"

using namespace std;

bool JacksOrBetter::isMatch(vector<Card> hand) const {
	bool jacksOrBetter{ false };

	vector<unsigned> ranks{ getSortedRanks(hand) };
	vector<unsigned> highRanks;
	highRanks.reserve(ranks.size());
	for (auto rank{ cbegin(ranks) }; rank != cend(ranks); ++rank) {
		if ((1 == (*rank)) || (*rank > 10)) {
			highRanks.push_back(*rank);
		}
	}

	if (highRanks.size() > 1) {
		jacksOrBetter = hasNMatches(highRanks, 2);
	}
	return jacksOrBetter;
}