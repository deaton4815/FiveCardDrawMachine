#pragma once

#include "wx/wx.h"
#include "wx/imagpng.h"
#include <vector>
#include <string>
#include <stdexcept>

#include "GUIInterface.h"

class fiveCardMain : public wxFrame
{
public:
	fiveCardMain(const wxString&, const wxPoint&, const wxSize&);

private:

	GUIInterface m_dealer;

	wxBoxSizer* m_mainSizer{ new wxBoxSizer(wxVERTICAL) }; // main layout sizer
	wxBoxSizer* m_cardSizer{ new wxBoxSizer(wxHORIZONTAL) }; // sizer for card images
	wxBoxSizer* m_bettingSizer{ new wxBoxSizer(wxHORIZONTAL) };// sizer for betting display

	wxStaticText* wagerDisplay;
	wxStaticText* fundsDisplay;

	wxComboBox* m_placeBetBox;
	wxButton* m_dealCardsButton{ new wxButton(this, wxID_ANY, wxT("Deal Cards"), wxDefaultPosition, wxDefaultSize) };

	std::vector<wxStaticBitmap*> m_cardBitmaps;  // Holds pointers to the card images
	std::vector<bool> m_cardSelections;  // Tracks selection state of each card

	wxStaticText* m_cardSelectionPrompt{ new wxStaticText(this, wxID_ANY, "Select cards to keep.", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER) };
	wxStaticText* m_selectedCardsText{ new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER) };
	wxButton* m_submitKeepersButton{ new wxButton(this, wxID_ANY, wxT("Submit Keepers"), wxDefaultPosition, wxDefaultSize) };

	void initializeWagerAndFundsDisplay();
	void initializeCardDisplay();
	void initializeBettingDisplay();
	void initializeCardSelection();

	void onNewHand(wxCommandEvent&);
	void onToggleCard(wxMouseEvent&);
	void onSubmitKeepers(wxCommandEvent&);

	void placeBet();
	void displayCards();

	void updateWagerDisplay();
	void updateFundsDisplay();
	void updateSelectedCardsDisplay();

	std::vector<std::string> getCardImages();
};