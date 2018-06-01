#ifndef _FILECONVER_
#define _FILECONVER_
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class FlieConvert
{
public:
    FlieConvert(int sizeli);
    FlieConvert();
    ~FlieConvert();

    bool setFile2Data(const string file);
    bool doConert();
    bool getData2Bin(const char *file);
    
private:
    int lineSize;
    Mat srcImage;
    Mat resImage;
    IplImage* src;
    IplImage* res;
    Vector<uchar> resBin;
};

#endif
