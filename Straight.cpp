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

unsigned Straight::getMultiplier() const { return m_multiplier; }
string Straight::getName() const { return m_name; }