#pragma once

#include <vector>
#include <string>

#include "Dealer.h"

class GUIInterface
{

public:
	void newHand();
	void setFinalHand(std::vector<bool>);
	void resetHand();

	bool setWagerAmount(unsigned);
	void addFunds(unsigned);
	unsigned cashOut();

	unsigned getWager() const;
	unsigned getFunds() const;

	unsigned getPayout() const;
	std::string getHandName() const;

	std::vector<std::string> getHandImageFileNames();

private:

	Dealer m_dealer;

	std::string getCardImageFileName(char, unsigned);

};

