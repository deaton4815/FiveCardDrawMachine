#include "Dealer.h"

using namespace std;

void Dealer::dealHand() {
	vector<Card> dealt = m_deck.getCards(m_hand.getHandSize());
	m_hand.newHand(dealt);
}