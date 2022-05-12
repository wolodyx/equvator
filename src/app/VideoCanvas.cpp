#include "VideoCanvas.h"

#include <wx/dcbuffer.h>
#include <wx/rawbmp.h>

#include <opencv2/opencv.hpp>


VideoCanvas::VideoCanvas(wxWindow* parent)
    : wxScrolledCanvas(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE)
{
    SetBackgroundColour(*wxBLACK);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    m_bitmap = new wxBitmap();

    Bind(wxEVT_PAINT, &VideoCanvas::OnPaint, this);
}


VideoCanvas::~VideoCanvas()
{
    delete m_bitmap;
}


namespace {;
bool Convert(const cv::Mat& img, wxBitmap& bitmap)
{
    bitmap.Create(img.cols, img.rows, 24);
    wxNativePixelData           pixelData(bitmap);
    wxNativePixelData::Iterator pixelDataIt(pixelData);
    const uchar* bgr = img.data;
    for(int row = 0; row < pixelData.GetHeight(); ++row)
    {
        pixelDataIt.MoveTo(pixelData, 0, row);

        for(int col = 0; col < pixelData.GetWidth(); ++col, ++pixelDataIt)
        {
            pixelDataIt.Blue()  = *bgr++;
            pixelDataIt.Green() = *bgr++;
            pixelDataIt.Red()   = *bgr++;
        }
    }

    return bitmap.IsOk();
}
}

bool VideoCanvas::LoadImage(const cv::Mat& img)
{
    if(!Convert(img,*m_bitmap))
        return false;
    Refresh();
    Update();
    return false;
}


void VideoCanvas::OnPaint(wxPaintEvent&)
{
    if(!m_bitmap || !m_bitmap->IsOk())
        return;

    wxAutoBufferedPaintDC dc(this);

    dc.Clear();
    DoPrepareDC(dc);

    dc.DrawBitmap(*m_bitmap, 0, 0, false);
}
