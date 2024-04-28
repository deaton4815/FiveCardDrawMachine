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

	wxBoxSizer* cardSizer;  // Sizer for the cards
	std::vector<wxStaticBitmap*> cardBitmaps;  // Holds pointers to the card images
	std::vector<bool> cardSelections;  // Tracks selection state of each card

	void OnNewGame(wxCommandEvent&);
	void OnToggleCard(wxMouseEvent&);
	std::vector<std::string> getCardImages();
};