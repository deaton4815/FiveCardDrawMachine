#include "fiveCardMain.h"

using namespace std;

fiveCardMain::fiveCardMain(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size) {

        // Initialize PNG handler for image loading
        wxImage::AddHandler(new wxPNGHandler());

        // Create a vertical sizer to stack the button and the card images
        wxBoxSizer* verticalSizer = new wxBoxSizer(wxVERTICAL);

        // Create a new button and bind the click event to an event handler
        wxButton* newGameBtn = new wxButton(this, wxID_ANY, wxT("New Game"), wxDefaultPosition, wxDefaultSize);
        newGameBtn->Bind(wxEVT_BUTTON, &fiveCardMain::OnNewGame, this);
        verticalSizer->Add(newGameBtn, 0, wxALL | wxCENTER, 5);

        // Create a horizontal sizer for card images to keep them in a single row
        cardSizer = new wxBoxSizer(wxHORIZONTAL);
        verticalSizer->Add(cardSizer, 1, wxALL | wxCENTER, 5);

        this->SetSizer(verticalSizer);
        this->Layout();
}

    void fiveCardMain::OnNewGame(wxCommandEvent& event) {

        m_dealerInterface.newGame();

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
        this->Layout();  // Update layout
    }

    void fiveCardMain::OnToggleCard(wxMouseEvent& event) {
        wxStaticBitmap* clickedBitmap = dynamic_cast<wxStaticBitmap*>(event.GetEventObject());
        int index = std::distance(cardBitmaps.begin(), std::find(cardBitmaps.begin(), cardBitmaps.end(), clickedBitmap));
        cardSelections[index] = !cardSelections[index];  // Toggle selection

        // Update the appearance based on selection
        if (cardSelections[index]) {
            clickedBitmap->SetWindowStyleFlag(wxBORDER_RAISED);
        }
        else {
            clickedBitmap->SetWindowStyleFlag(wxBORDER_SIMPLE);
        }
        clickedBitmap->Refresh();  // Force redraw of the bitmap
    }

    vector<string> fiveCardMain::getCardImages() {
        return m_dealerInterface.getHandImageFileNames();
    }