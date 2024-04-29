#include "TwoPair.h"

using namespace std;

bool TwoPair::isMatch(vector<Card> hand) const {
	bool twoPair{ false };

	vector<unsigned> ranks{ getSortedRanks(hand) };
	if (((ranks.at(0) == ranks.at(1)) && (ranks.at(2) == ranks.at(3)))
		|| ((ranks.at(0) == ranks.at(1)) && (ranks.at(3) == ranks.at(4)))
		|| ((ranks.at(1) == ranks.at(2)) && (ranks.at(3) == ranks.at(4)))) {
		twoPair = true;
	}
	return twoPair;
}

unsigned TwoPair::getMultiplier() const { return m_multiplier; }
string TwoPair::getName() const { return m_name; }