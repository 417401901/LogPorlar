#include "./src/FileConversion.h"

int main()
{
    FlieConvert FileCvt(256);

    if(FileCvt.setFile2Data("./timg.jpeg"))
        return 1;
    FileCvt.doConert();
    FileCvt.getData2Bin("./demo.txt");

    waitKey();
    FileCvt.~FlieConvert();
   
    return 0;
}