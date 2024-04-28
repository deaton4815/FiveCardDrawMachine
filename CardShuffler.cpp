#include "CardShuffler.h"

using namespace std;

CardShuffler::CardShuffler() {
	setShuffler();
}

vector<Card> CardShuffler::shuffleCards(vector<Card> cards) {
	shuffle(cards.begin(), cards.end(), m_shuffler);
	return cards;
}

void CardShuffler::setShuffler() {
	random_device seeder;
	const auto seed = seeder.entropy() ? seeder() : time(nullptr);
	default_random_engine e(seed);
	m_shuffler = e;
}