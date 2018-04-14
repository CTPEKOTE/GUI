// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#ifdef __BORLANDC__
#pragma hdrstop
#endif
/*
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <mathplot.h>

#include <wx/image.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/log.h>
#include <wx/intl.h>
*/
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame : public wxFrame
{
public:
    MyFrame();
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnMy(wxCommandEvent& event);
    void OnButtonOK(wxCommandEvent& event);
};
enum
{
    ID_Hello = 1
};
enum
{
    ID_My = 2
};
enum
{
    ID_ButtonOK = 3
};
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}
MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Test app")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenu *menuMy = new wxMenu;
    menuMy->Append(ID_My, "&My\tCtrl-M", "Does nothing");
    wxButton *MyButton = new wxButton(this, wxID_OK, wxT("OK"), wxPoint(200, 200)); 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    menuBar->Append(menuMy, "&My");
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MyFrame::OnMy, this, ID_My);
    Bind(wxEVT_BUTTON, &MyFrame::OnButtonOK, this, wxID_OK);
}   

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a Test app",
                 "About Test app", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Test GUI!");
}
void MyFrame::OnMy(wxCommandEvent& event)
{
    wxMessageBox("New upper button", "Title word", wxOK | wxICON_INFORMATION);
    SetStatusText("You have pushed upper button");
}
void MyFrame::OnButtonOK(wxCommandEvent& event){

    SetStatusText("Button is pushed!");
}
