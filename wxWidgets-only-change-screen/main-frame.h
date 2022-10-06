#ifndef main_frame_h
#define main_frame_h

#include <wx/wx.h>

class MainFrame : public wxFrame {
	private:

	public:
		MainFrame(const wxString &title);

		void ShowTest(const wxCommandEvent &evt);
		void ShowGame(const wxCommandEvent &evt);

		wxPanel *panelTop;
		wxPanel *panelMiddleLeft;
		wxPanel *panelMiddleRight;
		wxPanel *panelMiddleRight2;

		wxBoxSizer *sizerMain;
		wxBoxSizer *sizerTop;
		wxBoxSizer *sizerMiddle;
		wxBoxSizer *sizerMidRight;
		wxBoxSizer *sizerMidRightReal;
		wxBoxSizer *sizer6DOF;
		wxBoxSizer *sizer6DOFReal;


};

#endif