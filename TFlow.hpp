#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include "Car.hpp"

#define contour vector<Point>

using namespace std;
using namespace cv;

class TFlow
{
        private:
                VideoCapture vc;
                Mat ROITransform;
                Size ROISize;
                
                void orderPointsClockwise(vector<Point2f>& pts);
                Mat getTransMatrix(vector<Point2f>& src1, Size s);
                Mat getROI(Mat f);
                
                list<Car> cars;
                list<Car> fgDetected;
                void getCarsFG(Mat fg, Mat ROI, double time); //Fills fgDetected with the cars detected for a new instant of time
                void updateCars(Mat ROI, double time);        //Update cars by matching the newly detected with previous ones
                
        public:
                TFlow(){};
                void genConfig(string cFile);
                void loadConfig(string cFile);
                void play();
};

