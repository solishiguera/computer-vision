//
//  chapter3.cpp
//  opencvdiego
//
//  Created by Diego Solis on 7/12/21.
//

#include <stdio.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Chapter 3: Resize and crop
int main()  {
    string path = "Resources/test.png";
    Mat img = imread(path); // [768 x 559]
    Mat imgResize, imgCrop;
    
    resize(img, imgResize, Size(640,480)); // In pixels
    // resize(img, imgResize, Size(), 0.5, 0.5); // You can use scale/percentages
    cout << img.size() << endl;
    
    // Crop images
    Rect roi(100,100,300,250); // Rectangle data type
    imgCrop = img(roi);
    
    imshow("Image", img);
    imshow("Image resize", imgResize);
    imshow("Image crop", imgCrop);
    waitKey(0);
    
    return 0;
}
