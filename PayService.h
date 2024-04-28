#pragma once
class PayService
{

public:

	void addFunds();
	void addFunds(unsigned);
	bool wagerFunds(unsigned);

	unsigned getFunds() const;

private:

	unsigned m_funds{ 0 };

};

