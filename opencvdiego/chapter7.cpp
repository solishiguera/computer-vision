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

void getContours(Mat imgDil, Mat img) {
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    //drawContours(img, contours, -1, Scalar(255,120,255), 2); // -1 is to draw all contours
    vector< vector<Point> > conPoly(contours.size());
    vector<Rect> boundRect(contours.size());
    string objType;
    
    // Area filtration: remove areas smaller than 1000
    for(int position = 0; position < contours.size(); position++) {
        int area = contourArea(contours[position]);
        
        if (area > 1000) {
            float peri = arcLength(contours[position], true); // get perimeter
            approxPolyDP(contours[position], conPoly[position], 0.02 * peri, true); // How many sides
            drawContours(img, conPoly, position, Scalar(255,120,255), 2);
            cout << conPoly[position].size() << endl;
            boundRect[position] = boundingRect(conPoly[position]);
            rectangle(img, boundRect[position].tl(), boundRect[position].br(), Scalar(0,255,0), 5); // tl = top left, br = bottom right
            int objCor = (int) conPoly[position].size();
            
            // Check for sides
            if (objCor == 3)
                objType = "Tri";
            else if (objCor == 4)  {
                float aspRatio =  (float) boundRect[position].width / (float) boundRect[position].height;
                objType = (aspRatio > 0.95 && aspRatio < 1.05) ? "Square" : "Rect"; // Check if it is a square or rectangle
            }
            else if (objCor > 4)
                objType = "Circle";
            
            putText(img, objType, {boundRect[position].x, boundRect[position].y -  5}, FONT_HERSHEY_PLAIN, 0.8, Scalar(0,0,0), 2);
        }
    }
}

// Chapter 7: Shapes/contour detection
int main()  {
    string path = "Resources/shapes.png";
    Mat img = imread(path), imgGray, imgBlur, imgCanny, imgDil;
    
    // Preprocessing
    // BGR is convention in OpenCV,  like RGB
    cvtColor(img, imgGray, COLOR_BGR2GRAY); // Change from colored to grayscale
    // Noise reduction
    GaussianBlur(imgGray, imgBlur, Size(3,3), 3,0);
    // Edge detection algorithm; we have to remove noise first
    Canny(imgBlur, imgCanny, 20, 150);
    // These are primarily used to detect the shape of an object
    // Some edges are not connected, so we can dilate the edges to make them thicker
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5)); // Only use odd numbers for size
    dilate(imgCanny, imgDil, kernel);
    
    getContours(imgDil,img);
    
    imshow("Image", img);
    waitKey(0);
    return 0;
}

