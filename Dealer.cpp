#include "Dealer.h"

using namespace std;

void Dealer::newGame() {

	if (!m_firstHand) {
		m_deck.addCards(m_hand.getAllCards());
	}
	m_firstHand = false;

	m_hand.resetHand();
	//m_deck.shuffleDeck();
	dealHand();
}

void Dealer::executeKeeperSelection(vector<unsigned> keepers) {
	m_hand.setDiscards(keepers);
	vector<Card> replacements = m_deck.getCards(m_hand.getDiscardCount());
	m_hand.replaceDiscards(replacements);
}

size_t Dealer::getHandSize() const { return m_hand.getHandSize(); }
vector<char> Dealer::getHandSuits() const { return m_hand.getHandSuits(); }
vector<unsigned> Dealer::getHandRanks() const { return m_hand.getHandRanks(); }

void Dealer::dealHand() {
	vector<Card> dealt = m_deck.getCards(m_hand.getHandSize());
	m_hand.newHand(dealt);
}