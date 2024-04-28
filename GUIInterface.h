#pragma once

#include <vector>
#include <string>

#include "Dealer.h"

class GUIInterface
{

public:
	void newGame();
	std::vector<std::string> getHandImageFileNames();

private:

	Dealer m_dealer;

	std::string getCardImageFileName(char, unsigned);

};

