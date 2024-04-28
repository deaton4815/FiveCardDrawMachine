 #include "PokerHand.h"

using namespace std;

unsigned PokerHand::getMultiplier() const { return m_multiplier; }
string PokerHand::getName() const { return m_name; }

vector<unsigned> PokerHand::getSortedRanks(vector<Card> hand) const {
	vector<unsigned> ranks;
	ranks.reserve(hand.size());
	for (auto card{ cbegin(hand) }; card != cend(hand); ++card) {
		ranks.push_back(card->getRank());
	}
	sort(ranks.begin(), ranks.end());
	return ranks;
}

bool PokerHand::hasNMatches(vector<unsigned> values, unsigned n) const {
	bool nMatches{ false };

	unsigned count{ 1 };
	for (auto value{ cbegin(values) }; value != cend(values) - 1; ++value) {
		if (*value == *(value + 1)) {
			++count;
			if (n == count) {
				nMatches = true;
				break;
			}
		}
		else {
			count = 1;
		}
	}
	return nMatches;
}