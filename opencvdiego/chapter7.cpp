//
//  chapter7.cpp
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

void getContours(Mat &img) {
    //findContours(img, contours, hierarchy, RETR_EXTERNAL, <#int method#>);
}

// Chapter 7: Shapes/contour detection
int main()  {
    string path = "Resources/shapes.png";
    Mat img = imread(path);
    
    // Preprocessing
    // BGR is convention in OpenCV,  like RGB
    cvtColor(img, img, COLOR_BGR2GRAY); // Change from colored to grayscale
    // Noise reduction
    GaussianBlur(img, img, Size(3,3), 3,0);
    // Edge detection algorithm; we have to remove noise first
    Canny(img, img, 20, 150);
    // These are primarily used to detect the shape of an object
    // Some edges are not connected, so we can dilate the edges to make them thicker
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5)); // Only use odd numbers for size
    dilate(img, img, kernel);
    
    getContours(img);
    
    
    imshow("Image", img);
    waitKey(0);
    return 0;
}

