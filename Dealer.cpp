#include "Dealer.h"

using namespace std;

bool Dealer::setWager(unsigned wager) { return m_payService.wagerFunds(wager); }
void Dealer::addFunds(unsigned amount) { m_payService.addFunds(amount); }
unsigned Dealer::cashOut() { return m_payService.cashOut(); }

void Dealer::newHand() {
	m_deck.shuffleDeck();
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

unsigned Dealer::getWagerAmount() const { return m_payService.getWager(); }
unsigned Dealer::getFunds() const { return m_payService.getFunds(); }

void Dealer::dealHand() {
	vector<Card> dealt = m_deck.getCards(m_hand.getHandSize());
	m_hand.newHand(dealt);
}