//
//  chapter5.cpp
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

// Chapter 5: Warp perspective
int main()  {
    string path = "Resources/cards.jpg";
    Mat img = imread(path), matrix, imgWarp;
    float w = 610, h = 650;
    
    Point2f src[4] = {{778,108}, {1018,88}, {846,360}, {1116,331}}; // floating point
    Point2f dst[4] = {{0.0f,0.0f}, {w,0.0f}, {0.0f,h}, {w,h}};
    
    matrix = getPerspectiveTransform(src, dst); // Transformation matrix
    warpPerspective(img, imgWarp, matrix, Point(w,h));
    
    // create circles around points
    for (int i = 0; i < 4; i++) {
        circle(img, src[i], 10, Scalar(255,0,255), FILLED); // last value is thickness (int) or write FILLED
    }
    
    imshow("Image", img);
    imshow("Image Wrap", imgWarp);
    waitKey(0);
    
    return 0;
}
