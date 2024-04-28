#pragma once

#include <vector>
#include <string>

#include "Dealer.h"

class GUIInterface
{

public:
	void newGame();
	void executeKeeperSelection(std::vector<bool>);

	bool setWagerAmount(unsigned);
	unsigned getWager() const;
	unsigned getFunds() const;

	std::vector<std::string> getHandImageFileNames();

private:

	Dealer m_dealer;

	std::string getCardImageFileName(char, unsigned);

};

