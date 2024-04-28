#include "fiveCardApp.h"

wxIMPLEMENT_APP(fiveCardApp);

fiveCardApp::fiveCardApp() = default;
fiveCardApp::~fiveCardApp() = default;

bool fiveCardApp::OnInit() {

    fiveCardMain* m_frame = new fiveCardMain("Five Card Stud", wxPoint(50, 50), wxSize(450, 340));
    m_frame->Show(true);
    return true;
}