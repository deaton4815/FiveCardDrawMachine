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
	~fiveCardMain();

	void OnNewGame(wxCommandEvent&);

private:

	GUIInterface m_dealerInterface;

	std::vector<wxStaticBitmap*> cardBitmaps;  // Holds pointers to the card images

	std::vector<std::string> getCardImages();
};