#include "FourOfAKind.h"

using namespace std;

bool FourOfAKind::isMatch(vector<Card> hand) const {
	bool fourOfAKind{ false };

	vector<unsigned> ranks{ getSortedRanks(hand) };

	unsigned count{ 1 };
	for (auto rank{ cbegin(ranks) }; rank != cend(ranks) - 1; ++rank) {
		if (*rank == *(rank + 1)) {
			++count;
			if (4 == count) {
				fourOfAKind = true;
				break;
			}
		}
		else {
			count = 1;
		}
	}
	return fourOfAKind;
}