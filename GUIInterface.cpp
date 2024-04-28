#include "GUIInterface.h"

using namespace std;

void GUIInterface::newGame() { m_dealer.newGame(); }

vector<string> GUIInterface::getHandImageFileNames() {
	vector<string> images;

	vector<char> suits{ m_dealer.getHandSuits() };
	vector<unsigned> ranks{ m_dealer.getHandRanks() };

	size_t size{ suits.size() };
	images.reserve(size);
	for (size_t i{ 0 }; i < size; ++i) {
		images.push_back(getCardImageFileName(suits.at(i), ranks.at(i)));
	}
	return images;
}

string GUIInterface::getCardImageFileName(char suit, unsigned rank) {

	string rankString{ to_string(rank) };

	string path{ "card_images/" };
	string extension{ ".png" };

	string filename = path + suit + rankString + extension;
	return filename;
}