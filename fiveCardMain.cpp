#include "fiveCardMain.h"

fiveCardMain::fiveCardMain()
	:wxFrame(nullptr, wxID_ANY, "FiveCardStud", wxPoint(30, 30), wxSize(800, 600))
{

	m_btn1 = new wxButton(this, wxID_ANY, "Click Me", wxPoint(10, 10), wxSize(150, 50));
}

fiveCardMain::~fiveCardMain() = default;