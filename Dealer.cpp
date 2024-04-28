#include "Dealer.h"

using namespace std;

void Dealer::newGame() {
	dealHand();
}

vector<char> Dealer::getHandSuits() const { return m_hand.getHandSuits(); }
vector<unsigned> Dealer::getHandRanks() const { return m_hand.getHandRanks(); }

void Dealer::dealHand() {
	vector<Card> dealt = m_deck.getCards(m_hand.getHandSize());
	m_hand.newHand(dealt);
}