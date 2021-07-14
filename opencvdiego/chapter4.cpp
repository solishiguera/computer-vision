//
//  chapter4.cpp
//  opencvdiego
//
//  Created by Diego Solis on 7/13/21.
//

#include <stdio.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Chapter 4: Drawing shapes and text
int main()  {
    
    // Create a blank img
    // CV_8UC3: 8 bit image, unsigned (0->255), 3 channels (BGR)
    Mat img(512,512,CV_8UC3, Scalar(255, 255, 255));
    
    circle(img, Point(256,256), 100, Scalar(255,0,255), FILLED); // last value is thickness (int) or write FILLED
    rectangle(img, Point(10,10), Point(150,150), Scalar(0,255,0), 10);
    
    line(img, Point(200, 300), Point(300,300), Scalar(255,255,0), 5);
    
    putText(img, "hello, world!", Point(100,100), FONT_HERSHEY_SIMPLEX, 2, Scalar(0,0,0), 2);
    
    imshow("Image", img);
    waitKey(0);
    
    return 0;
}
