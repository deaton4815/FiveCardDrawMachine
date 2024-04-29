#pragma once
class PayService
{

public:

	void addFunds();
	void addFunds(unsigned);
	bool wagerFunds(unsigned);
	
	void resetWager();
	unsigned cashOut();

	unsigned getFunds() const;
	unsigned getWager() const;

private:

	unsigned m_funds{ 0 };
	unsigned m_wager{ 0 };

};

