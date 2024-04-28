 #include "PokerHand.h"

using namespace std;

vector<unsigned> PokerHand::getSortedRanks(vector<Card> hand) const {
	vector<unsigned> ranks;
	ranks.reserve(hand.size());
	for (auto card{ cbegin(hand) }; card != cend(hand); ++card) {
		ranks.push_back(card->getRank());
	}
	sort(ranks.begin(), ranks.end());
	return ranks;
}