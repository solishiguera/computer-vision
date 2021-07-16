//
//  chapter8.cpp
//  opencvdiego
//
//  Created by Diego Solis on 7/15/21.
//

#include <stdio.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp> // Haarcascade
#include <iostream>

using namespace cv;
using namespace std;

// Chapter 8: Face Detection
int main()  {
    string path = "Resources/test.png";
    Mat img = imread(path);
    
    CascadeClassifier face;
    face.load("Resources/haarcascade_frontalface_default.xml");
    
    vector<Rect> faces;
    face.detectMultiScale(img, faces, 1.1, 10);
    
    for (int position = 0; position < faces.size(); position++) {
        rectangle(img, faces[position].tl(), faces[position].br(), Scalar(56,255,128), 3);
    }
    
    imshow("Image", img);
    waitKey(0);
    
    return 0;
}


