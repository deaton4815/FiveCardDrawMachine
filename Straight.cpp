#include "Straight.h"

using namespace std;

bool Straight::isMatch(vector<Card> hand) const {
	vector<unsigned> ranks{ getSortedRanks(hand)};

	bool straight{ true };
	unsigned difference{ 0 };
	for (auto rank{ cbegin(ranks) }; rank != cend(ranks) - 1; ++rank) {
		difference = *(rank + 1) - (*rank);
		if ((difference != 1) && (difference != 9)) {
			straight = false;
			break;
		}
	}
	return straight;
}

vector<unsigned> Straight::getSortedRanks(vector<Card> hand) const {
	vector<unsigned> ranks;
	ranks.reserve(hand.size());
	for (auto card{ cbegin(hand) }; card != cend(hand); ++card) {
		ranks.push_back(card->getRank());
	}
	sort(ranks.begin(), ranks.end());
	return ranks;
}