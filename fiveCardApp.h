#pragma once

#include "wx/wx.h"
#include "fiveCardMain.h"

class fiveCardApp : public wxApp
{
public:
	fiveCardApp();
	~fiveCardApp();

	virtual bool OnInit();

private:
	fiveCardMain* m_frame1 = nullptr;
};