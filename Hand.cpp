#include "Hand.h"

using namespace std;

void Hand::newHand(const vector<Card>& cards) { m_hand = cards; }

void Hand::setDiscards(const vector<unsigned>& keeps) {
	setDiscardIndices(keeps);
	setDiscardedCards();
}

void Hand::replaceDiscards(const vector<Card>& replacements) {
	for (size_t i{ 0 }; i < replacements.size(); ++i) {
		m_hand.at(m_discardIndices.at(i)) = replacements.at(i);
	}
}

void Hand::resetHand() {
	m_hand.clear();
	m_discardIndices.clear();
	m_discards.clear();
}

size_t Hand::getDiscardCount() const { return m_discardIndices.size(); }

vector<Card> Hand::getAllCards() const {
	vector<Card> allCards{ m_hand };
	allCards.insert(allCards.end(), m_discards.begin(), m_discards.end());
	return allCards;
}

void Hand::setDiscardIndices(const vector<unsigned>& keeps) {
	for (size_t i{ 0 }; i < m_handSize; ++i) {
		if (!isKeeper(i, keeps)) {
			m_discardIndices.push_back(i);
		}
	}
}

void Hand::setDiscardedCards() {
	for (size_t i{ 0 }; i < m_discardIndices.size(); ++i) {
		m_discards.push_back(m_hand.at(m_discardIndices.at(i)));
	}
}

bool Hand::isKeeper(const unsigned i, const vector<unsigned>& keeps) const {
	bool isKeeper{ false };
	for (size_t j{ 0 }; j < keeps.size(); ++j) {
		if (i == keeps.at(j)) {
			isKeeper = true;
			break;
		}
	}
	return isKeeper;
}