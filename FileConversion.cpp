#include <stdio.h>
#include <iostream>
#include <fstream> 
#include "opencv2/opencv.hpp"
#include "FileConversion.h"

using namespace std;
using namespace cv;
/******************************************************
 * Copyright(C), 2018, SLDX Ambition
 * 本程序用于全息LED灯的格式转换 .jpg .png .bmp -> .bin
 * 程序基于opencv2.7版本库编写
 * 作者：wangx
 * 版本：1.0.0 2018.5.31 初步完成对于图像的极坐标转换
 * 
 ******************************************************/

int main()
{
    
    return 0;
}

/*******************************************************
 * 函数：文件读取函数
 * 输入：文件路径 示例："./file.jpg"
 * 输出：完成 0 出错 1
 * 其他：输入文件需为图片格式
 * 
 ******************************************************/
bool FlieConvert::setFile2Data(const string file)
{
    srcImage = imread(file);

    if(srcImage.empty())
    {
        cout << "Image is error." << endl;
        return 1;
    }
        
    return 0;
}

/*******************************************************
 * 函数：文件处理函数
 * 输入：无
 * 输出：无
 * 其他：进行实际的转化工作
 *      1.由直角坐标转化为极坐标
 *      2.由极坐标图转化为bin
 ******************************************************/
bool FlieConvert::doConert()
{
    IplImage* src = &IplImage(srcImage);
    IplImage* res = NULL;
    cvLinearPolar(src, res, cvPoint2D32f(src->width / 2,src->height / 2), 256, CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);
    resImage = cvarrToMat(res);
}

/*******************************************************
 * 函数：文件输出函数
 * 输入：要输出的文件位置 .bin
 * 输出：完成 0 出错 1
 * 其他：进行实际的转化工作
 *      1.由直角坐标转化为极坐标
 *      2.由极坐标图转化为bin
 ******************************************************/
bool FlieConvert::getData2Bin(const string file)
{
    ofstream binfile(file, ios::out|ios::trunc);
    
}

FlieConvert::FlieConvert()
{

}

FlieConvert::~FlieConvert()
{

}