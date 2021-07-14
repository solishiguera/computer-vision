//
//  chapter6.cpp
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

// Chapter 6: color detection
int main()  {
    string path = "Resources/shapes.png";
    Mat img = imread(path), imgRange, imgHSV;
    int hmin = 0, smin = 0, vmin = 0;
    int hmax = 179, smax = 255, vmax = 255;
    
    //  HSV is an alternative representations of the RGB color model
    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    
    //Trackbar
    namedWindow("Trackbars", (static_cast<void>(640),200));
    createTrackbar("Hue Minimum", "Trackbars", &hmin, 179); // 179 is max value;
    createTrackbar("Hue Maximum", "Trackbars", &hmax, 179);
    createTrackbar("saturation Minimum", "Trackbars", &smin, 255);
    createTrackbar("saturation Maximum", "Trackbars", &smax, 255);
    createTrackbar("value Minimum", "Trackbars", &vmin, 255);
    createTrackbar("value Maximum", "Trackbars", &vmax, 255);
    
    
    while(true) {
        // hmin -> hue min, smin -> saturation min, vmin -> value min
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, imgRange); // use ranges because of color differences
            
        imshow("Image", img);
        imshow("Image hsv", imgHSV);
        imshow("Image range", imgRange);
        waitKey(1);
    }
    
    return 0;
}
