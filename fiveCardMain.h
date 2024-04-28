#pragma once

#include "wx/wx.h"
#include "wx/imagpng.h"
#include <vector>
#include <string>
#include <stdexcept>

#include "CardUI.h"
#include "GUIInterface.h"

class fiveCardMain : public wxFrame
{
public:
	fiveCardMain(const wxString&, const wxPoint&, const wxSize&);

private:

	wxBoxSizer* m_mainSizer{ new wxBoxSizer(wxVERTICAL) };

	CardUI m_cardInterface;
	GUIInterface m_dealerInterface;

	wxButton* submitKeepersBtn;
	wxComboBox* placeBetBox;
	wxStaticText* wagerDisplay;
	wxStaticText* fundsDisplay;

	void initializePlaceBetBox(wxBoxSizer*);
	void initializeSubmitKeepersButton(wxBoxSizer*);

	void OnNewGame(wxCommandEvent&);
	void OnSubmitKeepers(wxCommandEvent&);

	void displayCards();

	void setWagerAmount();
	void updateWagerDisplay();
	void updateFundsDisplay();
	std::vector<std::string> getCardImages();
};