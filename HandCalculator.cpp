#include "HandCalculator.h"

using namespace std;

void HandCalculator::calculateHand(vector<Card> hand) {

	array<PokerHand*, 9> pokerHands;
	pokerHands[0] = new RoyalFlush;
	pokerHands[1] = new StraightFlush;
	pokerHands[2] = new FourOfAKind;
	pokerHands[3] = new FullHouse;
	pokerHands[4] = new Flush;
	pokerHands[5] = new Straight;
	pokerHands[6] = new ThreeOfAKind;
	pokerHands[7] = new TwoPair;
	pokerHands[8] = new JacksOrBetter;

	for (size_t i{ 0 }; i < pokerHands.size(); ++i) {

	}
}