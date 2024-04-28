#include "HandCalculator.h"

using namespace std;

HandCalculator::HandCalculator() {
	m_pokerHands[0] = new RoyalFlush;
	m_pokerHands[1] = new StraightFlush;
	m_pokerHands[2] = new FourOfAKind;
	m_pokerHands[3] = new FullHouse;
	m_pokerHands[4] = new Flush;
	m_pokerHands[5] = new Straight;
	m_pokerHands[6] = new ThreeOfAKind;
	m_pokerHands[7] = new TwoPair;
	m_pokerHands[8] = new JacksOrBetter;
}

HandCalculator::~HandCalculator() {
	for (size_t i{ 0 }; i < m_pokerHands.size(); ++i) {
		delete m_pokerHands[i];
	}
}

void HandCalculator::calculateHand(vector<Card> hand) {
	bool match{ false };
	for (size_t i{ 0 }; i < m_pokerHands.size(); ++i) {
		if (m_pokerHands[i]->isMatch(hand)) {
			m_multiplier = m_pokerHands[i]->getMultiplier();
			m_name = m_pokerHands[i]->getName();

			match = true;
			break;
		}
	}
	if (!match) {
		m_multiplier = 0;
		m_name = "Losing Hand";
	}
}