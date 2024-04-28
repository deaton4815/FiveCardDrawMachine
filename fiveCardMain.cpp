#include "fiveCardMain.h"

using namespace std;

fiveCardMain::fiveCardMain(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size) 
{
    // Initialize PNG handler for image loading
    wxImage::AddHandler(new wxPNGHandler());

    // Initialize display window
    initializeWagerAndFundsDisplay();
    initializeCardDisplay();
    initializeBettingDisplay();
    initializeCardSelection();

    this->SetSizer(m_mainSizer);
    this->Layout();
}

void fiveCardMain::initializeWagerAndFundsDisplay() {
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
}

void fiveCardMain::initializeCardDisplay() {
    // Display cards
    m_mainSizer->Add(m_cardSizer, 0, wxALIGN_CENTER | wxALL, 5);
    displayCards();
}

// Initialize pre-hand betting display
void fiveCardMain::initializeBettingDisplay() {
    m_mainSizer->Add(m_bettingSizer, 0, wxALIGN_LEFT | wxALL, 5);

    // Place bet box
    m_bettingSizer->Add(m_wagerLabel, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    wxString betOptions[] = { wxT("1"), wxT("2"), wxT("3"), wxT("4"), wxT("5") };
    m_placeBetBox = new wxComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 5, betOptions, wxCB_READONLY);
    m_bettingSizer->Add(m_placeBetBox, 0, wxALL, 5);
    m_placeBetBox->SetSelection(0);  // Selects the first item in the list, "1"

    // Deal cards button
    m_dealCardsButton->Bind(wxEVT_BUTTON, &fiveCardMain::onNewHand, this);
    m_bettingSizer->Add(m_dealCardsButton, 0, wxALL, 5);

    //Insert Coin button
    m_insertCoinButon->Bind(wxEVT_BUTTON, &fiveCardMain::onInsertCoin, this);
    m_bettingSizer->Add(m_insertCoinButon, 0, wxALL, 5);

    //Cash out button
    m_cashOutButton->Bind(wxEVT_BUTTON, &fiveCardMain::onCashOut, this);
    m_bettingSizer->Add(m_cashOutButton, 0, wxALL, 5);
}

// Card selection
void fiveCardMain::initializeCardSelection() {

    // Static text for selection prompt, initially hidden
    m_cardSelectionPrompt->Hide();
    m_mainSizer->Add(m_cardSelectionPrompt, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

    // Static text for displaying selected cards, initially hidden
    m_selectedCardsText->Hide();  // Initially hidden
    m_mainSizer->Add(m_selectedCardsText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

    //Submit Keeprs button, initially hidden
    m_submitKeepersButton->Bind(wxEVT_BUTTON, &fiveCardMain::onSubmitKeepers, this);
    m_submitKeepersButton->Hide();  // Initially hide the button
    m_mainSizer->Add(m_submitKeepersButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);
}

    void fiveCardMain::onNewHand(wxCommandEvent& event) {

        // Place bet
        bool sufficientFunds{ placeBet() };
        
        if (sufficientFunds) {

            // Hide wagering buttons
            m_wagerLabel->Hide();
            m_placeBetBox->Hide();
            m_dealCardsButton->Hide();
            m_insertCoinButon->Hide();
            m_cashOutButton->Hide();

            // New hand
            m_dealer.newHand();
            displayCards();

            // Display card selection
            m_cardSelectionPrompt->Show();  // Show the selection prompt
            updateSelectedCardsDisplay();
            m_selectedCardsText->Show();  // Show the selected cards text only after cards are loaded
            m_submitKeepersButton->Show();
            this->Layout();  // Update layout
        }
    }

    void fiveCardMain::onInsertCoin(wxCommandEvent& event) {

        // Add coin to funds
        m_dealer.addFunds(1);
        updateFundsDisplay();
        this->Layout();
    }

    void fiveCardMain::onCashOut(wxCommandEvent& event) {
        unsigned cashVoucher{ m_dealer.cashOut() };
        wxMessageBox(wxString::Format("Printing cash voucher for %u coins", cashVoucher));
        updateFundsDisplay();
        this->Layout();
    }

    void fiveCardMain::onToggleCard(wxMouseEvent& event) {
        wxStaticBitmap* clickedBitmap = dynamic_cast<wxStaticBitmap*>(event.GetEventObject());
        size_t index = std::distance(m_cardBitmaps.begin(), std::find(m_cardBitmaps.begin(), m_cardBitmaps.end(), clickedBitmap));
        m_cardSelections[index] = !m_cardSelections[index];  // Toggle selection
        updateSelectedCardsDisplay();  // Update the display text
    }

    void fiveCardMain::onSubmitKeepers(wxCommandEvent& event) {
        // Implement functionality to handle the submission of selected cards

        m_cardSelectionPrompt->Hide();
        m_selectedCardsText->Hide();
        m_submitKeepersButton->Hide();

        m_dealer.executeKeeperSelection(m_cardSelections);
        displayCards();
        this->Layout();
    }

    bool fiveCardMain::placeBet() {

        // Get selected bet
        wxString selectedBet = m_placeBetBox->GetValue();

        // Set wager amount
        unsigned wager = stoul(selectedBet.ToStdString(), 0, 10);
        bool sufficientFunds{ m_dealer.setWagerAmount(wager) };
        if (!sufficientFunds) {
            wxMessageBox("Insufficient Funds");
        }
        else {
            updateWagerDisplay();
            updateFundsDisplay();
        }
        return sufficientFunds;
    }

    void fiveCardMain::updateWagerDisplay() {
        unsigned wager = m_dealer.getWager();  // Assuming this is how you get the wager
        wagerDisplay->SetLabel(wxString::Format("Wager: %u", wager));
    }

    void fiveCardMain::updateFundsDisplay() {
        unsigned funds = m_dealer.getFunds();  // Assuming this is how you get the funds
        fundsDisplay->SetLabel(wxString::Format("Funds: %u", funds));
    }

    void fiveCardMain::updateSelectedCardsDisplay() {
        wxString selectedText = "Selected Cards: ";
        bool found = false;
        for (size_t i = 0; i < m_cardSelections.size(); ++i) {
            if (m_cardSelections[i]) {
                selectedText += wxString::Format("Card %d, ", int(i + 1));
                found = true;
            }
        }
        if (!found) {
            selectedText = "No cards selected";
        }
        m_selectedCardsText->SetLabel(selectedText);
    }

    void fiveCardMain::displayCards() {

        // Clear previous images and selections if any
        for (auto& bitmap : m_cardBitmaps) {
            bitmap->Destroy();
        }
        m_cardBitmaps.clear();
        m_cardSelections.clear();

        // Clear existing cards from sizer before adding new ones
        m_cardSizer->Clear(true);

        const int cardWidth = 100;
        const int cardHeight = 150;

        // Load new images, resize them, and display them
        std::vector<std::string> cardImages = getCardImages();
        if (cardImages.empty()) {
            wxLogError("No card images available to display.");
            return;
        }
        for (const std::string& imagePath : cardImages) {
            wxImage image(wxString(imagePath), wxBITMAP_TYPE_PNG);
            if (!image.IsOk()) {
                wxLogError("Failed to load image from path: %s", imagePath);
                continue;
            }

            // Card bitmap
            image.Rescale(cardWidth, cardHeight);
            wxStaticBitmap* bitmap = new wxStaticBitmap(this, wxID_ANY, wxBitmap(image));
            bitmap->Bind(wxEVT_LEFT_DOWN, &fiveCardMain::onToggleCard, this);
            m_cardBitmaps.push_back(bitmap);
            m_cardSelections.push_back(false);
            m_cardSizer->Add(bitmap, 0, wxALL, 5);
        }
    }

    vector<string> fiveCardMain::getCardImages() { return m_dealer.getHandImageFileNames(); }