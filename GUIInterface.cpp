#include "GUIInterface.h"

using namespace std;

void GUIInterface::newGame() { m_dealer.newGame(); }

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

void GUIInterface::executeKeeperSelection(vector<bool> selections) {
	vector<unsigned> keepers;
	for (size_t i{ 0 }; i < selections.size(); ++i) {
		if (selections.at(i)) {
			keepers.push_back(static_cast<unsigned>(i));
		}
	}
	m_dealer.executeKeeperSelection(keepers);
}

bool GUIInterface::setWagerAmount(unsigned wager) {return m_dealer.setWager(wager); }

unsigned GUIInterface::getWager() const { return m_dealer.getWagerAmount(); }
unsigned GUIInterface::getFunds() const { return m_dealer.getFunds(); }

string GUIInterface::getCardImageFileName(char suit, unsigned rank) {

	string rankString{ to_string(rank) };

	string path{ "card_images/" };
	string extension{ ".png" };

	string filename = path + suit + rankString + extension;
	return filename;
}