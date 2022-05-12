#include "DataProvider.h"

#include <opencv2/videoio.hpp>


DataProvider::DataProvider()
{
    m_cap = new cv::VideoCapture(0);
}


DataProvider::~DataProvider()
{
    delete m_cap;
}


bool DataProvider::GetFrame(cv::Mat& mat)
{
    if(!m_cap->isOpened())
        return false;
    return m_cap->read(mat);
}
