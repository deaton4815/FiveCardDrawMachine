#include "StraightFlush.h"

using namespace std;

bool StraightFlush::isMatch(vector<Card> hand) {
	bool straightFlush{ false };

	if (m_straight.isMatch(hand) && m_flush.isMatch(hand)) {
		straightFlush = true;
	}

	return straightFlush;
}