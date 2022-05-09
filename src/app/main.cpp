#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "VideoCanvas.h"


class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};


class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
private:
    VideoCanvas* m_canvas;
};


enum
{
    ID_Hello = 1
};


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_Hello,   MainFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MainFrame *frame = new MainFrame( "Hello World", wxPoint(50, 50), wxSize(450, 340) );
    frame->Show( true );
    return true;
}


MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Open File...\tCtrl-O", "Load file");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );

    auto panel = new wxPanel(this);
    m_canvas = new VideoCanvas(panel);
    auto panelSizer = new wxBoxSizer(wxVERTICAL);
    panelSizer->Add(m_canvas, 1, wxEXPAND);
    panel->SetSizer(panelSizer);
}


void MainFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}


void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}


void MainFrame::OnHello(wxCommandEvent& event)
{
    wxFileDialog dlg(this,
        ("Open XYZ file"),
        "",
        "",
        "Image files (*.bmp;*.gif;*.png)|*.bmp;*.gif;*.png",
        wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if(dlg.ShowModal() == wxID_CANCEL)
        return;

    if(!m_canvas->LoadImage(dlg.GetPath()))
        return;
}
