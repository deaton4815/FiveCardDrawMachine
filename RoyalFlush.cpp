#include "RoyalFlush.h"

using namespace std;

bool RoyalFlush::isMatch(vector<Card> hand) const {
	bool royalFlush{ false };

	vector<unsigned> ranks{ getSortedRanks(hand) };
	if (m_straightFlush.isMatch(hand)
		&& ((1 == ranks.front()) && (13 == ranks.back()))) {
		royalFlush = true;
	}
	return royalFlush;
}

unsigned RoyalFlush::getMultiplier() const { return m_multiplier; }
string RoyalFlush::getName() const { return m_name; }