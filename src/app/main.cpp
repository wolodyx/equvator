#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <opencv2/opencv.hpp>

#include "DataProvider.h"
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
    void OnTimer(wxTimerEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
private:
    wxTimer* m_timer;
    DataProvider m_provider;
    VideoCanvas* m_canvas;
};


enum
{
    ID_Timer = 1
};


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_TIMER(ID_Timer,  MainFrame::OnTimer)
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

    m_timer = new wxTimer(this, ID_Timer);
    m_timer->Start(1000);
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


void MainFrame::OnTimer(wxTimerEvent& event)
{
    cv::Mat img;
    m_provider.GetFrame(img);

    auto sz = this->GetClientSize();
    cv::Mat img2;
    resize(img, img2, cv::Size(sz.x,sz.y), cv::INTER_LINEAR);

    if(!m_canvas->LoadImage(img2))
        return;
}
