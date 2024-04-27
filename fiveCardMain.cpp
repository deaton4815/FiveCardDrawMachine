#include "fiveCardMain.h"

using namespace std;

fiveCardMain::fiveCardMain(const wxString& title, const wxPoint& pos, const wxSize& size)
	:wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // Initialize PNG handler for image loading
    wxImage::AddHandler(new wxPNGHandler());

    // Create a new button and bind the click event to an event handler
    wxButton* newGameBtn = new wxButton(this, wxID_ANY, wxT("New Game"), wxDefaultPosition, wxDefaultSize);
    newGameBtn->Bind(wxEVT_BUTTON, &fiveCardMain::OnNewGame, this);

    // Initialize the sizer for layout and add the button
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(newGameBtn, 0, wxALL, 5);
    this->SetSizer(sizer);
    this->Layout();
}

fiveCardMain::~fiveCardMain() = default;

// Event handler for the button click
void fiveCardMain::OnNewGame(wxCommandEvent& event) {
    std::vector<std::string> cardImages = GetCardImages();  // Get card images from an external function
    wxBoxSizer* sizer = dynamic_cast<wxBoxSizer*>(this->GetSizer());

    // Clear previous images if any
    for (wxStaticBitmap* bitmap : cardBitmaps) {
        bitmap->Destroy(); // This will automatically remove the bitmap from the sizer
    }
    cardBitmaps.clear();

    // Load new images and display them
    for (const std::string& imagePath : cardImages) {
        wxImage image(wxString(imagePath), wxBITMAP_TYPE_PNG);
        if (!image.IsOk()) {
            wxLogError("Failed to load image from path: %s", imagePath);
            continue;
        }
        wxStaticBitmap* bitmap = new wxStaticBitmap(this, wxID_ANY, wxBitmap(image));
        cardBitmaps.push_back(bitmap);
        sizer->Add(bitmap, 0, wxALL, 5);
    }
    this->Layout();  // Update layout
}
