#include "PayService.h"

void PayService::addFunds() { ++m_funds; }
void PayService::addFunds(unsigned winnings) { m_funds += winnings; }

bool PayService::wagerFunds(unsigned wager) {
	bool placed{ false };
	if (wager <= m_funds) {
		m_funds -= wager;
		m_wager = wager;
		placed = true;
	}
	return placed;
}

void PayService::resetWager() { m_wager = 0; }
unsigned PayService::cashOut() {
	unsigned cashVoucher{ getFunds()};
	m_funds = 0;
	return cashVoucher;
}

unsigned PayService::getFunds() const { return m_funds; }
unsigned PayService::getWager() const { return m_wager; }