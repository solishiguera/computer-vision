//
//  main.cpp
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


/*
// Image
int main() {
    string path = "Resources/test.png";
    Mat img = imread(path); // Matrix data type
    
    imshow("Foto", img);
    waitKey(0); // 0 for infinity
     
    return 0;
}
*/


/*
// Video
int main() {
    string path = "Resources/test_video.mp4";
    VideoCapture cap(path);
    Mat img;
    
    while (true) {
        cap.read(img);
        
        imshow("Foto", img);
        waitKey(1); // 1 for millisecond
    }
    
    
    return 0;
}
*/


// Webcam
int main() {
    VideoCapture cap(0); // 0 is camera id number
    Mat img;
    
    while (true) {
        cap.read(img);
        
        imshow("Foto", img);
        waitKey(1); // 1 for millisecond
    }
    return 0;
}

