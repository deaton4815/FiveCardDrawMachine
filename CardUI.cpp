#include "CardUI.h"

using namespace std;

CardUI::CardUI(wxBoxSizer* mainSizer) {

    // Initialize PNG handler for image loading
    wxImage::AddHandler(new wxPNGHandler());

    // Card sizer
    m_cardSizer = new wxBoxSizer(wxHORIZONTAL);
    mainSizer->Add(m_cardSizer, 0, wxALIGN_CENTER | wxALL, 5);
}

void CardUI::intializeCardSelection(wxBoxSizer* mainSizer) {
    // Card selection prompt
    initializeCardSelectionPrompt(mainSizer);

    // Static text for displaying selected cards, initially hidden
    initializeSelectedCardsText(mainSizer);
}

// Static text for selection prompt, initially hidden
void CardUI::initializeCardSelectionPrompt(wxBoxSizer* sizer) {
    m_selectionPrompt = new wxStaticText(this, wxID_ANY, "Select cards to keep.", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    m_selectionPrompt->Hide();
    sizer->Add(m_selectionPrompt, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);
}

// Static text for displaying selected cards, initially hidden
void CardUI::initializeSelectedCardsText(wxBoxSizer* sizer) {
    m_selectedCardsText = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    m_selectedCardsText->Hide();  // Initially hidden
    sizer->Add(m_selectedCardsText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);
}

void CardUI::newHand(vector<string> cardFiles) {

    displayCards(cardFiles);

    m_selectionPrompt->Show(); // Show selection prompt
    updateSelectedCardsDisplay();
    m_selectedCardsText->Show(); // Show selected cards once cards are displayed
}

vector<bool> CardUI::keepersSelected() {
    m_selectionPrompt->Hide();
    m_selectedCardsText->Hide();
    return m_cardSelections;
}

void CardUI::displayCards(vector<string> cardFiles) {

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
    for (const std::string& imagePath : cardFiles) {
        wxImage image(wxString(imagePath), wxBITMAP_TYPE_PNG);
        if (!image.IsOk()) {
            wxLogError("Failed to load image from path: %s", imagePath);
            continue;
        }

        image.Rescale(cardWidth, cardHeight);
        wxStaticBitmap* bitmap = new wxStaticBitmap(this, wxID_ANY, wxBitmap(image));
        bitmap->Bind(wxEVT_LEFT_DOWN, &CardUI::onToggleCard, this);
        m_cardBitmaps.push_back(bitmap);
        m_cardSelections.push_back(false);
        m_cardSizer->Add(bitmap, 0, wxALL, 5);
    }
}

void CardUI::onToggleCard(wxMouseEvent& event) {
    wxStaticBitmap* clickedBitmap = dynamic_cast<wxStaticBitmap*>(event.GetEventObject());
    size_t index = std::distance(m_cardBitmaps.begin(), std::find(m_cardBitmaps.begin(), m_cardBitmaps.end(), clickedBitmap));
    m_cardSelections[index] = !m_cardSelections[index];  // Toggle selection
    updateSelectedCardsDisplay();  // Update the display text
}

void CardUI::updateSelectedCardsDisplay() {
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