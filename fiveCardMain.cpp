#include "fiveCardMain.h"

using namespace std;

fiveCardMain::fiveCardMain(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
    , m_cardInterface(m_mainSizer)
{

    // Top display sizer for Wager and Funds
    wxBoxSizer* topDisplaySizer = new wxBoxSizer(wxHORIZONTAL);
    m_mainSizer->Add(topDisplaySizer, 0, wxEXPAND | wxALL, 5);

    // Wager display
    wagerDisplay = new wxStaticText(this, wxID_ANY, "Wager: ", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
    topDisplaySizer->Add(wagerDisplay, 1, wxEXPAND | wxALL, 5);
    updateWagerDisplay();  // Function to set text from external function

    // Funds display
    fundsDisplay = new wxStaticText(this, wxID_ANY, "Funds: ", wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    topDisplaySizer->Add(fundsDisplay, 1, wxEXPAND | wxALL, 5);
    updateFundsDisplay();  // Function to set text from external function

    // Display Card Backs
    m_cardInterface.displayCards(getCardImages());

    // Betting sizer
    wxBoxSizer* bettingSizer = new wxBoxSizer(wxHORIZONTAL);
    m_mainSizer->Add(bettingSizer, 0, wxALIGN_LEFT | wxALL, 5);

    // Place bet box
    initializePlaceBetBox(bettingSizer);

    // Deal cards button
    wxButton* dealCardsBtn = new wxButton(this, wxID_ANY, wxT("Deal Cards"), wxDefaultPosition, wxDefaultSize);
    dealCardsBtn->Bind(wxEVT_BUTTON, &fiveCardMain::OnNewGame, this);
    bettingSizer->Add(dealCardsBtn, 0, wxALL, 5);

    // Card selection intialization
    m_cardInterface.intializeCardSelection(m_mainSizer);

    // Submit keepers button
    initializeSubmitKeepersButton(m_mainSizer); 

    this->SetSizer(m_mainSizer);
    this->Layout();
}

// Place bet box
void fiveCardMain::initializePlaceBetBox(wxBoxSizer* sizer) {
    wxStaticText* wagerLabel = new wxStaticText(this, wxID_ANY, wxT("Wager:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    sizer->Add(wagerLabel, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    wxString betOptions[] = { wxT("1"), wxT("2"), wxT("3"), wxT("4"), wxT("5") };
    placeBetBox = new wxComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 5, betOptions, wxCB_READONLY);
    sizer->Add(placeBetBox, 0, wxALL, 5);

    // Set the default selection for the place bet box
    placeBetBox->SetSelection(0);  // Selects the first item in the list, "1"
}

// Submit Keepers button, initially hidden
void fiveCardMain::initializeSubmitKeepersButton(wxBoxSizer* sizer) {
    submitKeepersBtn = new wxButton(this, wxID_ANY, wxT("Submit Keepers"), wxDefaultPosition, wxDefaultSize);
    submitKeepersBtn->Bind(wxEVT_BUTTON, &fiveCardMain::OnSubmitKeepers, this);
    submitKeepersBtn->Hide();  // Initially hide the button
    sizer->Add(submitKeepersBtn, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);
}

    void fiveCardMain::OnNewGame(wxCommandEvent& event) {

        wxString selectedBet = placeBetBox->GetValue();
        wxMessageBox(wxString::Format("Coin inserted for bet of %s.", selectedBet), "Coin Inserted", wxOK | wxICON_INFORMATION, this);

        string wager = selectedBet.ToStdString();
        unsigned long lresult = stoul(wager, 0, 10);
        unsigned result = lresult;
        if (result != lresult) throw out_of_range("Invald wager conversion!");
        m_dealerInterface.setWagerAmount(result);
        updateWagerDisplay();
        updateFundsDisplay();

        m_dealerInterface.newGame();

        m_cardInterface.newHand(getCardImages());
        submitKeepersBtn->Show();
        this->Layout();  // Update layout
    }

    void fiveCardMain::OnSubmitKeepers(wxCommandEvent& event) {
        // Implement functionality to handle the submission of selected cards

        vector<bool> cardSelections = m_cardInterface.keepersSelected();
        submitKeepersBtn->Hide();
        m_dealerInterface.executeKeeperSelection(cardSelections);
        m_cardInterface.displayCards(getCardImages());
        this->Layout();
    }

    void fiveCardMain::updateWagerDisplay() {
        unsigned wager = m_dealerInterface.getWager();  // Assuming this is how you get the wager
        wagerDisplay->SetLabel(wxString::Format("Wager: %u", wager));
    }

    void fiveCardMain::updateFundsDisplay() {
        unsigned funds = m_dealerInterface.getFunds();  // Assuming this is how you get the funds
        fundsDisplay->SetLabel(wxString::Format("Funds: %u", funds));
    }

    vector<string> fiveCardMain::getCardImages() {
        vector<string> cardFiles{ m_dealerInterface.getHandImageFileNames() };
        if (cardFiles.empty()) {
            wxLogError("No card images available to display.");
        }
        return cardFiles;
    }