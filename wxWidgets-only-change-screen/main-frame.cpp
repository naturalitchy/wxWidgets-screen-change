#include "main-frame.h"

MainFrame::MainFrame(const wxString &title)
	: wxFrame(nullptr, 33, title) {
	CreateStatusBar();

	sizerMain = new wxBoxSizer(wxVERTICAL);					// Main sizer (injection sizerTop and sizerMiddlePlusBottom)
	sizerTop = new wxBoxSizer(wxVERTICAL);					// Top sizer (use sizerMain)
	sizerMiddle = new wxBoxSizer(wxHORIZONTAL);				// Middle sizer (use sizerMiddlePlusBottom)

	sizerMidRight = new wxBoxSizer(wxVERTICAL);				// Main화면의 Button들을 정렬해줄 sizer
	sizerMidRightReal = new wxBoxSizer(wxVERTICAL);			// sizerMidRight를 받아 sizerMiddle에 주입할 sizer
	sizer6DOF = new wxBoxSizer(wxVERTICAL);					// 6DOF화면의 Button들을 정렬해줄 sizer
	sizer6DOFReal = new wxBoxSizer(wxVERTICAL);				// sizer6DOF를 받아 sizerMiddle에 주입할 sizer


	panelTop = new wxScrolledWindow(this);							// use the sizerTop
	panelMiddleLeft = new wxScrolledWindow(this);					// 
	panelMiddleRight = new wxScrolledWindow(this);
	panelMiddleRight2 = new wxScrolledWindow(this);
	panelTop->SetBackgroundColour(*wxBLACK);
	panelMiddleLeft->SetBackgroundColour(*wxGREEN);
	panelMiddleRight->SetBackgroundColour(*wxBLUE);
	panelMiddleRight2->SetBackgroundColour(*wxRED);


	wxButton *btnGameChoo = new wxButton(panelMiddleLeft, wxID_ANY, "Choose the Game", wxDefaultPosition, wxSize(150, 50));
	wxButton *btnSetting = new wxButton(panelMiddleLeft, wxID_ANY, "Setting", wxDefaultPosition, wxSize(150, 50));
	wxButton *btnDofTest = new wxButton(panelMiddleLeft, wxID_ANY, "6DOF Test", wxDefaultPosition, wxSize(150, 50));
	btnDofTest->Bind(wxEVT_BUTTON, &MainFrame::ShowTest, this);
	wxBoxSizer *sizerMidLeft = new wxBoxSizer(wxVERTICAL);
	btnGameChoo->SetBackgroundColour(wxColor(61, 51, 61));
	btnSetting->SetBackgroundColour(wxColor(60, 50, 60));
	btnDofTest->SetBackgroundColour(wxColor(60, 40, 60));
	sizerMidLeft->Add(btnGameChoo, 0, wxEXPAND | wxALL, 10);
	sizerMidLeft->Add(btnSetting, 0, wxEXPAND | wxALL, 10);
	sizerMidLeft->Add(btnDofTest, 0, wxEXPAND | wxALL, 10);
	panelMiddleLeft->SetSizer(sizerMidLeft);

	for (int i = 0; i < 15; i++) {
		wxButton *btn1 = new wxButton(panelMiddleRight, wxID_ANY, "Button1", wxPoint(10, 20 * i), wxSize(30, 50));
		sizerMidRight->Add(btn1, 1, wxEXPAND | wxALL, 10);
	}
	panelMiddleRight->SetSizer(sizerMidRight);
	sizerMidRightReal->Add(panelMiddleRight, 1, wxEXPAND | wxALL);

	for (int i = 0; i < 25; i++) {
		wxButton *btn1 = new wxButton(panelMiddleRight2, wxID_ANY, "Zero", wxPoint(50, 70 * i), wxSize(150, 50));
		//sizer6DOF->Add(btn1, 1, wxEXPAND | wxALL, 10);
	}
	//panelMiddleRight2->SetSizer(sizer6DOF);
	sizer6DOFReal->Add(panelMiddleRight2, 1, wxEXPAND | wxALL);
	sizer6DOFReal->ShowItems(false);


	sizerTop->Add(panelTop, 1, wxEXPAND | wxALL);
	sizerMiddle->Add(panelMiddleLeft, 1, wxEXPAND | wxALL);
	// This screen is basic panel
	sizerMiddle->Add(sizerMidRightReal, 4, wxEXPAND | wxALL);
	// This screen is 6DOF panel
	sizerMiddle->Add(sizer6DOFReal, 4, wxEXPAND | wxALL);
	sizerMain->Add(sizerTop, 1, wxEXPAND | wxALL);
	sizerMain->Add(sizerMiddle, 3, wxEXPAND | wxALL);

	this->SetSizer(sizerMain);


}

void MainFrame::ShowTest(const wxCommandEvent &evt) {
	sizerMidRightReal->ShowItems(false);
	sizer6DOFReal->ShowItems(true);
	sizerMain->Layout();

}
void MainFrame::ShowGame(const wxCommandEvent &evt) {
}
