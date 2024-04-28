#include "PayService.h"

void PayService::addFunds() { ++m_funds; }
void PayService::addFunds(unsigned winnings) { m_funds += winnings; }

bool PayService::wagerFunds(unsigned wager) {
	bool placed{ false };
	if (wager < m_funds) {
		m_funds -= wager;
		placed = true;
	}
	return placed;
}

unsigned PayService::getFunds() const { return m_funds; }