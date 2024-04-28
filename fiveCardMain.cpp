#include "fiveCardMain.h"

using namespace std;

fiveCardMain::fiveCardMain(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size) 
    , selectionPrompt(nullptr)
    , selectedCardsText(nullptr)
    , submitKeepersBtn(nullptr)
{

    // Initialize PNG handler for image loading
    wxImage::AddHandler(new wxPNGHandler());

    // Main layout sizer
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Top display sizer for Wager and Funds
    wxBoxSizer* topDisplaySizer = new wxBoxSizer(wxHORIZONTAL);
    mainSizer->Add(topDisplaySizer, 0, wxEXPAND | wxALL, 5);

    // Wager display
    wagerDisplay = new wxStaticText(this, wxID_ANY, "Wager: ", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
    topDisplaySizer->Add(wagerDisplay, 1, wxEXPAND | wxALL, 5);
    updateWagerDisplay();  // Function to set text from external function

    // Funds display
    fundsDisplay = new wxStaticText(this, wxID_ANY, "Funds: ", wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    topDisplaySizer->Add(fundsDisplay, 1, wxEXPAND | wxALL, 5);
    updateFundsDisplay();  // Function to set text from external function

    // Sizer for the cards
    cardSizer = new wxBoxSizer(wxHORIZONTAL);
    mainSizer->Add(cardSizer, 0, wxALIGN_CENTER | wxALL, 5);
    displayCards();

    // Betting sizer
    wxBoxSizer* bettingSizer = new wxBoxSizer(wxHORIZONTAL);
    mainSizer->Add(bettingSizer, 0, wxALIGN_LEFT | wxALL, 5);

    // Place bet box
    initializePlaceBetBox(bettingSizer);

    // Deal cards button
    wxButton* dealCardsBtn = new wxButton(this, wxID_ANY, wxT("Deal Cards"), wxDefaultPosition, wxDefaultSize);
    dealCardsBtn->Bind(wxEVT_BUTTON, &fiveCardMain::OnNewGame, this);
    bettingSizer->Add(dealCardsBtn, 0, wxALL, 5);

    // Card selection prompt
    initializeCardSelectionPrompt(mainSizer);

    // Static text for displaying selected cards, initially hidden
    initializeSelectedCardsText(mainSizer);

    // Submit keepers button
    initializeSubmitKeepersButton(mainSizer); 

    this->SetSizer(mainSizer);
    this->Layout();
}

// Place bet box
void fiveCardMain::initializePlaceBetBox(wxBoxSizer* sizer) {
    wxStaticText* wagerLabel = new wxStaticText(this, wxID_ANY, wxT("Wager:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    sizer->Add(wagerLabel, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    wxString betOptions[] = { wxT("1"), wxT("2"), wxT("3"), wxT("4"), wxT("5") };
    placeBetBox = new wxComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 5, betOptions, wxCB_READONLY);
    sizer->Add(placeBetBox, 0, wxALL, 5);
}

// Static text for selection prompt, initially hidden
void fiveCardMain::initializeCardSelectionPrompt(wxBoxSizer* sizer) {
    selectionPrompt = new wxStaticText(this, wxID_ANY, "Select cards to keep.", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    selectionPrompt->Hide();
    sizer->Add(selectionPrompt, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);
}

// Static text for displaying selected cards, initially hidden
void fiveCardMain::initializeSelectedCardsText(wxBoxSizer* sizer) {
    selectedCardsText = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    selectedCardsText->Hide();  // Initially hidden
    sizer->Add(selectedCardsText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);
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

        //newGameBtn->Hide();
        m_dealerInterface.newGame();

        displayCards();
        
        selectionPrompt->Show();  // Show the selection prompt
        UpdateSelectedCardsDisplay();
        selectedCardsText->Show();  // Show the selected cards text only after cards are loaded
        submitKeepersBtn->Show();
        this->Layout();  // Update layout
    }

    void fiveCardMain::OnToggleCard(wxMouseEvent& event) {
        wxStaticBitmap* clickedBitmap = dynamic_cast<wxStaticBitmap*>(event.GetEventObject());
        size_t index = std::distance(cardBitmaps.begin(), std::find(cardBitmaps.begin(), cardBitmaps.end(), clickedBitmap));
        cardSelections[index] = !cardSelections[index];  // Toggle selection
        UpdateSelectedCardsDisplay();  // Update the display text
    }

    void fiveCardMain::UpdateSelectedCardsDisplay() {
        wxString selectedText = "Selected Cards: ";
        bool found = false;
        for (size_t i = 0; i < cardSelections.size(); ++i) {
            if (cardSelections[i]) {
                selectedText += wxString::Format("Card %d, ", int(i + 1));
                found = true;
            }
        }
        if (!found) {
            selectedText = "No cards selected";
        }
        selectedCardsText->SetLabel(selectedText);
    }

    void fiveCardMain::OnSubmitKeepers(wxCommandEvent& event) {
        // Implement functionality to handle the submission of selected cards

        selectionPrompt->Hide();
        selectedCardsText->Hide();
        submitKeepersBtn->Hide();

        m_dealerInterface.executeKeeperSelection(cardSelections);
        displayCards();
        this->Layout();
    }

    void fiveCardMain::displayCards() {

        // Clear previous images and selections if any
        for (auto& bitmap : cardBitmaps) {
            bitmap->Destroy();
        }
        cardBitmaps.clear();
        cardSelections.clear();

        // Clear existing cards from sizer before adding new ones
        cardSizer->Clear(true);

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

            image.Rescale(cardWidth, cardHeight);
            wxStaticBitmap* bitmap = new wxStaticBitmap(this, wxID_ANY, wxBitmap(image));
            bitmap->Bind(wxEVT_LEFT_DOWN, &fiveCardMain::OnToggleCard, this);
            cardBitmaps.push_back(bitmap);
            cardSelections.push_back(false);
            cardSizer->Add(bitmap, 0, wxALL, 5);
        }
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
        return m_dealerInterface.getHandImageFileNames();
    }