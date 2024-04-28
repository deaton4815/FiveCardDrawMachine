#pragma once

#include "wx/wx.h"
#include "wx/imagpng.h"
#include <vector>
#include <string>

#include "GUIInterface.h"

class fiveCardMain : public wxFrame
{
public:
	fiveCardMain(const wxString&, const wxPoint&, const wxSize&);

private:

	GUIInterface m_dealerInterface;

	wxButton* newGameBtn;
	wxBoxSizer* cardSizer;  // Sizer for the cards
	wxStaticText* selectedCardsText;  // Text control for displaying selected cards
	std::vector<wxStaticBitmap*> cardBitmaps;  // Holds pointers to the card images
	std::vector<bool> cardSelections;  // Tracks selection state of each card
	wxButton* submitKeepersBtn;
	wxStaticText* selectionPrompt; // Prompt for selecting cards

	void initializeNewGameButton(wxBoxSizer*);
	void initializeCardSelectionPrompt(wxBoxSizer*);
	void initializeSelectedCardsText(wxBoxSizer*);
	void intializeSubmitKeepersButton(wxBoxSizer*);

	void OnNewGame(wxCommandEvent&);
	void OnToggleCard(wxMouseEvent&);
	void OnSubmitKeepers(wxCommandEvent&);

	void UpdateSelectedCardsDisplay();
	std::vector<std::string> getCardImages();
};