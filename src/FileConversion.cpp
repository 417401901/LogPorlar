#include <stdio.h>
#include <iostream>
#include <fstream> 
#include "opencv2/opencv.hpp"
#include "FileConversion.h"
#define DEBUG true
/******************************************************
 * Copyright(C), 2018, SLDX Ambition
 * 本程序用于全息LED灯的格式转换 .jpg .png .bmp -> .bin
 * 程序基于opencv2.7版本库编写
 * 作者：wangx
 * 版本：1.0.0 2018.5.31 初步完成对于图像的极坐标转换
 * 
 ******************************************************/

using namespace std;
using namespace cv;

/*******************************************************
 * 函数：文件读取函数
 * 输入：文件路径 示例："./file.jpg"
 * 输出：完成 0 出错 1
 * 其他：输入文件需为图片格式
 * 
 ******************************************************/
bool FlieConvert::setFile2Data(const string file)
{
    int resize_W, resize_H, size_MAX;

    
    srcImage = imread(file);

    if(srcImage.empty())
    {
        cout << "Image is error." << endl;
        return 1;
    }

    if(srcImage.cols > srcImage.rows)
    {
        resize_W = (int)(lineSize * 1414 / 1000);
        resize_H = srcImage.rows*resize_W/srcImage.cols;
    }
    else
    {
        resize_H = (int)(lineSize * 1414 / 1000);
        resize_W = srcImage.cols*resize_H/srcImage.rows;
    }

    src = cvCreateImage(Size(resize_W, resize_H), 8, 3);
    resize(srcImage, srcImage, Size(resize_W, resize_H));

#if DEBUG
    cout << "图片转换到IplImage完成" << resize_W << resize_H << srcImage << endl;
#endif
    *src = IplImage(srcImage); 



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
    res = cvCreateImage(Size(lineSize, (int)(lineSize*2754/1000)), 8, 3);
    cvLinearPolar(src, res, cvPoint2D32f(src->width / 2,src->height / 2), lineSize, CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);
#if DEBUG
    cout << "图片完成" << endl;
#endif
    resImage = cvarrToMat(res);
    imshow("图片", resImage);
    imshow("图片源", srcImage);
}

/*******************************************************
 * 函数：文件输出函数
 * 输入：要输出的文件位置 .bin
 * 输出：完成 0 出错 1
 * 其他：进行实际的转化工作
 *      1.由直角坐标转化为极坐标
 *      2.由极坐标图转化为bin
 ******************************************************/
bool FlieConvert::getData2Bin(const char* file)
{
    ofstream binfile(file, ios::out);
    
    for(int angle = 0; angle < resImage.rows; angle++)
        for(int r = 0; r < resImage.cols; r++)
            for(int i = 2; i >= 0; i--)
                binfile << resImage.at<Vec3b>(angle, r)[i];

    binfile.close();
}
FlieConvert::FlieConvert(int sizeli)
{
    this->lineSize = sizeli;
}
FlieConvert::FlieConvert()
{

}
FlieConvert::~FlieConvert()
{

}