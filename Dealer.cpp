#include "Dealer.h"

using namespace std;

bool Dealer::setWager(unsigned wager) { return m_payService.wagerFunds(wager); }
void Dealer::addFunds(unsigned amount) { m_payService.addFunds(amount); }
unsigned Dealer::cashOut() { return m_payService.cashOut(); }

void Dealer::newHand() {
	m_deck.shuffleDeck();
	dealHand();
}

void Dealer::setFinalHand(vector<unsigned> keepers) {
	executeKeepers(keepers);
	calculateHand();
}

void Dealer::resetHand() {
	// Reset pay service
	m_payService.addFunds(getPayout());
	m_payService.resetWager();

	// Reset hand
	m_hand.resetHand();
}

size_t Dealer::getHandSize() const { return m_hand.getHandSize(); }
vector<char> Dealer::getHandSuits() const { return m_hand.getHandSuits(); }
vector<unsigned> Dealer::getHandRanks() const { return m_hand.getHandRanks(); }

unsigned Dealer::getWagerAmount() const { return m_payService.getWager(); }
unsigned Dealer::getFunds() const { return m_payService.getFunds(); }

unsigned Dealer::getPayout() const { return getWagerAmount() * getMultiplier(); }
string Dealer::getHandName() const { return m_calculator.getHandName(); }

void Dealer::dealHand() {
	vector<Card> dealt = m_deck.getCards(m_hand.getHandSize());
	m_hand.newHand(dealt);
}

void Dealer::executeKeepers(vector<unsigned> keepers) {
	m_hand.setDiscards(keepers);
	vector<Card> replacements = m_deck.getCards(m_hand.getDiscardCount());
	m_hand.replaceDiscards(replacements);
}

void Dealer::calculateHand() {
	vector<Card> hand{ m_hand.getHand() };
	m_calculator.calculateHand(hand);
}

unsigned Dealer::getMultiplier() const { return m_calculator.getMultiplier(); }