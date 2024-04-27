#pragma once

#include "wx/wx.h"
#include <vector>
#include <string>
#include "wx/imagpng.h"

class fiveCardMain : public wxFrame
{
public:
	fiveCardMain(const wxString&, const wxPoint&, const wxSize&);
	~fiveCardMain();

	void OnNewGame(wxCommandEvent&);

private:
	std::vector<wxStaticBitmap*> cardBitmaps;  // Holds pointers to the card images

	std::vector<std::string> getCardImages();
};