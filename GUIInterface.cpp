#include "GUIInterface.h"

using namespace std;

void GUIInterface::newHand() { m_dealer.newHand(); }

vector<string> GUIInterface::getHandImageFileNames() {

	size_t handSize{ m_dealer.getHandSize() };

	vector<string> images;
	images.reserve(handSize);

	vector<char> suits{ m_dealer.getHandSuits() };
	vector<unsigned> ranks{ m_dealer.getHandRanks() };

	if (suits.empty() || ranks.empty()) {
		vector<string> cardBacks(handSize, "card_images/back.png");
		images = cardBacks;
	}
	else {
		for (size_t i{ 0 }; i < handSize; ++i) {
			images.push_back(getCardImageFileName(suits.at(i), ranks.at(i)));
		}
	}
	return images;
}

void GUIInterface::setFinalHand(vector<bool> selections) {
	vector<unsigned> keepers;
	for (size_t i{ 0 }; i < selections.size(); ++i) {
		if (selections.at(i)) {
			keepers.push_back(static_cast<unsigned>(i));
		}
	}
	m_dealer.setFinalHand(keepers);
}

void GUIInterface::resetHand() { m_dealer.resetHand(); }

bool GUIInterface::setWagerAmount(unsigned wager) {return m_dealer.setWager(wager); }
void GUIInterface::addFunds(unsigned deposit) { m_dealer.addFunds(deposit); }
unsigned GUIInterface::cashOut() { return m_dealer.cashOut(); }
unsigned GUIInterface::getWager() const { return m_dealer.getWagerAmount(); }
unsigned GUIInterface::getFunds() const { return m_dealer.getFunds(); }
unsigned GUIInterface::getPayout() const { return m_dealer.getPayout(); }
string GUIInterface::getHandName() const { return m_dealer.getHandName(); }

string GUIInterface::getCardImageFileName(char suit, unsigned rank) {

	string rankString{ to_string(rank) };

	string path{ "card_images/" };
	string extension{ ".png" };

	string filename = path + suit + rankString + extension;
	return filename;
}