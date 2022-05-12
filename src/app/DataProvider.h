#ifndef APP_DATAPROVIDER_H
#define APP_DATAPROVIDER_H

namespace cv { class VideoCapture; }
namespace cv { class Mat; }


class DataProvider
{
public:
    DataProvider();
    ~DataProvider();

    bool GetFrame(cv::Mat&);

private:
    cv::VideoCapture* m_cap;
};

#endif // APP_DATAPROVIDER_H
