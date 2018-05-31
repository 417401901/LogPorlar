#ifndef _FILECONVER_
#define _FILECONVER_
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class FlieConvert
{
public:
    FlieConvert::FlieConvert();
    FlieConvert::~FlieConvert();

    bool setFile2Data(const string file);
    bool doConert();
    bool getData2Bin(const string file);
private:
    Mat srcImage;
    Mat resImage;
    Vector<uchar> resBin;
}

#endif