//
//  chapter2.cpp
//  opencvdiego
//
//  Created by Diego Solis on 7/11/21.
//


#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Chapter 2 Basic functions
int main()  {
    string path = "Resources/test.png";
    Mat img = imread(path); // Matrix data type
    Mat imgGray, imgBlur, imgCanny, imgDilate, imgErosion, test;
    
    // BGR is convention in OpenCV,  like RGB
    cvtColor(img, imgGray, COLOR_BGR2GRAY); // Change from colored to grayscale
    
    // Noise reduction
    GaussianBlur(img, imgBlur, Size(3,3), 3,0);
    
    // Edge detection algorithm; we have to remove noise first
    Canny(imgBlur, imgCanny, 20, 150);
    
    // These are primarily used to detect the shape of an object
    // Some edges are not connected, so we can dilate the edges to make them thicker
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5)); // Only use odd numbers for size
    dilate(imgCanny, imgDilate, kernel);
    
    // Erosion
    erode(imgDilate, imgErosion, kernel);
    
    //imshow("Foto", img);
    //imshow("Gaussian Blur", imgBlur);
    
    imshow("Image Dilate", imgDilate);
    imshow("Image Erosion", imgErosion);
    
    
    waitKey(0); // 0 for infinity
     
    return 0;
}
