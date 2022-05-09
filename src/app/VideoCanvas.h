#ifndef APP_VIDEOCANVAS_H
#define APP_VIDEOCANVAS_H

#include <wx/wx.h>
#include <wx/scrolwin.h>


class VideoCanvas : public wxScrolledCanvas
{
public:
    VideoCanvas(wxWindow*);
    virtual ~VideoCanvas();

    bool LoadImage(const wxString& fileName);

private:
    void OnPaint(wxPaintEvent&);

private:
    wxBitmap* m_bitmap;
};
#endif // APP_VIDEOCANVAS_H
