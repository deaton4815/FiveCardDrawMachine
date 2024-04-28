#include "FullHouse.h"

using namespace std;

bool FullHouse::isMatch(vector<Card> hand) const {
	vector<unsigned> ranks{ getSortedRanks(hand) };

}