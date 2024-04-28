#include "ThreeOfAKind.h"

using namespace std;

bool ThreeOfAKind::isMatch(vector<Card> hand) const {
	bool threeOfAKind{ false };

	vector<unsigned> ranks{ getSortedRanks(hand) };

	unsigned count{ 1 };
	for (auto rank{ cbegin(ranks) }; rank != cend(ranks) - 1; ++rank) {
		if (*rank == *(rank + 1)) {
			++count;
			if (3 == count) {
				threeOfAKind = true;
				break;
			}
		}
		else {
			count = 1;
		}
	}
	return threeOfAKind;
}