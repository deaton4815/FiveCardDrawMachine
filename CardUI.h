#pragma once

#include "wx/wx.h"
#include "wx/imagpng.h"

#include <vector>
#include <string>

class CardUI : public wxFrame
{
public:

	CardUI(wxBoxSizer*);

	void intializeCardSelection(wxBoxSizer*);

	void newHand(std::vector<std::string>);
	std::vector<bool> keepersSelected();

	void displayCards(std::vector<std::string>);

private:

	wxBoxSizer* m_cardSizer;

	wxStaticText* m_selectionPrompt; // Prompt for selecting cards
	wxStaticText* m_selectedCardsText;  // Text control for displaying selected cards
	wxButton* m_submitKeepersBtn;

	std::vector<wxStaticBitmap*> m_cardBitmaps;  // Holds pointers to the card images
	std::vector<bool> m_cardSelections;  // Tracks selection state of each card

	void initializeCardSelectionPrompt(wxBoxSizer*);
	void initializeSelectedCardsText(wxBoxSizer*);

	void onToggleCard(wxMouseEvent&);
	void updateSelectedCardsDisplay();
};