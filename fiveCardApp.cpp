#include "fiveCardApp.h"

wxIMPLEMENT_APP(fiveCardApp);

fiveCardApp::fiveCardApp() = default;
fiveCardApp::~fiveCardApp() = default;

bool fiveCardApp::OnInit() {

	m_frame1 = new fiveCardMain();
	m_frame1->Show();

	return true;
}