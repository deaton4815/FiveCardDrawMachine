#pragma once

#include "wx/wx.h"

class fiveCardMain : public wxFrame
{
public:
	fiveCardMain();
	~fiveCardMain();

	wxButton* m_btn1 = nullptr;
	wxTextCtrl* m_text1 = nullptr;
	wxListBox* m_list1 = nullptr;
};