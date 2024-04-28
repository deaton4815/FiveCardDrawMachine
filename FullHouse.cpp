#include "FullHouse.h"

using namespace std;

bool FullHouse::isMatch(vector<Card> hand) const {
	bool fullHouse{ false };

	vector<unsigned> ranks{ getSortedRanks(hand) };
	if ((ranks.at(0) == ranks.at(2) && ranks.at(3) == ranks.at(4)) ||
		(ranks.at(0) == ranks.at(1) && ranks.at(2) == ranks.at(4))) {
		fullHouse = true;
	}
	return fullHouse;
}