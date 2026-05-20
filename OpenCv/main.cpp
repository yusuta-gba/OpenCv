#include <iostream>
#include <stdio.h>
#include <string.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <fstream>
using namespace std;
using namespace cv;

int RED[37][2] = {   
                    {140,45},
                    {140,46},
                    { 140,47},
                    { 140,48},
                    { 141,44},
                    { 141,45},
                    { 141,46},
                    { 141,47},
                    { 141,48},
                    { 141,49},
                    { 141,50},
                    { 141,51},
                    {147, 50},
                    {148, 47},
                    {148, 48},
                    {148, 49},
                    {148, 50},
                    {148, 51},
                    {149, 43},
                    {149, 48},
                    {149, 49},
                    { 149, 50},
                    {149, 51},
                    { 150, 43},
                    { 150, 44},
                    { 150, 47},
                    { 150, 48},
                    { 150, 49},
                    { 150, 50},
                    {150, 51},
                    { 151, 43},
                    { 151, 44},
                    { 151, 45},
                    { 151, 46},
                    { 151, 48},
                    { 151, 49},
                    { 151, 50}};

int BLUE[124][2] = {
    {16,4},
    {16,5},
    {16,6},
    {16,7},
    {16,8},
    {16,9},
    {16,10},
    {16,11},
    {16,15},
    {16,17},
    {16,18},
    {16,19},
   {16,20},
   {16,21},
   {16,22},
   {25,4},
   {25,5},
   {25,6},
   {25,7},
   {25,8},
   {25,9},
   {25,10},
   {25,11},
   {25,15},
   {25,16},
   {25,17},
   {25,18},
   {25,19},
   {25,20},
   {25,21},
   {25,22},
   {28,4},
   {28,5},
   {28,6},
   {28,7},
   {28,8},
   {28,9},
   {28,10},
   {28,11},
   {28,15},
   {28,16},
   {28,17},
   {28,18},
   {28,19},
   {28,20},
   {28,21},
   {28,22},
   {34,42},
   {34,54},
   {35,42},
   {35,54},
   {36,42},
   {36,54},
   {37,4},
   {37,5},
{37,6},
{37,7},
{37,8},
{37,9},
{37,10},
{37,11},
{37,15},
{37,16},
{37,17},
{37,18},
{37,19},
{37,20},
{37,21},
{37,22},
{37,42},
{37,54},
{38,42},
{38,54},
{39,42},
{39,54},
{40,42},
{40,54},
{142,44},
{142,45},
{142,46},
{142,47},
{143,43},
{143,46},
{143,49},
{144,43},
{144,46},
{144,47},
{144,50},
{145,42},
{145,43},
{145,44},
{145,49},
{145,50},
{145,51},
{145,52},
{146,43},
{146,44},
{147,43},
{147,44},
{147,45},
{147,46 },
{147,47 },
{147,48 },
{147,49 },
{148,43 },
{148,44 },
{148,45 },
{148,46 },
{149,44 },
{152,43 },
{152,44 },
{152,45 },
{152,48 },
{152,49 },
{152,50 },
{153,43 },
{153,44 },
{153,45 },
{153,46 },
{153,48 },
{153,49 },
{153,50 },
{153,51} };

int YELLOW[32][2] = {
{142,48},
{142,49},
{143,44},
{143,45},
{143,47},
{143,48},
{143,50},
{143,51},
{143,52},
{144,44},
{144,45},
{144,48},
{144,49},
{144,51},
{144,52},
{144,53},
{145,45},
{145,46},
{145,47},
{145,48},
{146,45},
{146,46},
{146,47},
{146,48},
{146,49},
{146,50},
{146,51},
{149,45},
{149,46},
{149,47},
{150,45},
{150, 46}};
int c = 0;
int d = 0;
int e = 0;
Vec3b black;
Vec3b bridge;
queue<pair<int, int>>future_RED;
queue<pair<int, int>>future_BLUE;
queue<pair<int, int>>future_YELLOW;
int main() {
    cout << "Hello, World!" << endl;
    cout << "OpenCV version is " << CV_VERSION << endl;
    string imagePath = "C:/Users/yetam/source/repos/OpenCv/OpenCv/Screenshot.png";
    ofstream outputFile;
    outputFile.open("C:/Users/yetam/source/repos/OpenCv/OpenCv/output12.csv", ios::out | ios::app);
    Mat image = imread(imagePath, IMREAD_COLOR);
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            Vec3b pix = image.at<Vec3b>(i, j);
			if (i == 0 && j == 0)
                 black = image.at<Vec3b>(0, 0);
            
            int r = pix[0], g = pix[1], b = pix[2];
          
            
            
            if (r == 255 && g == 66 && b == 41)
            {

                if (i == RED[c][0] && j == RED[c][1]) {
                    c++;
                    if (j + 15 < image.cols) {
                        image.at<Vec3b>(i, j + 15) = pix;
                    }
                                                      }


            }  
            
            
            if (r == 82 && g == 33 && b == 222)
            {

                if (i == BLUE[d][0] && j == BLUE[d][1])
                                                        {
                    d++;
                    if (j + 15 < image.cols) {
                        image.at<Vec3b>(i, j + 15) = pix;
                    }

                                                        }
            }    
            
            if (r == 255 && g == 222 && b == 181)
            {
                if (i == YELLOW[e][0] && j == YELLOW[e][1])
                {
                    e++;
                    if (j + 15 < image.cols) {
                        image.at<Vec3b>(i, j + 15) = pix;
                    }

                }
            } 

            if (r == 255 && g == 66 && b == 107)
            {
                bridge = pix;
            }
            
        }


    }
    
	for (int i = 0; i < 37; i++) {
            image.at<Vec3b>(RED[i][0], RED[i][1]) = black;
	}
	for (int i = 0; i < 124; i++) {
		image.at<Vec3b>(BLUE[i][0], BLUE[i][1]) = black;
        if (i >= 115 && i <= 123)
        {
            image.at<Vec3b>(BLUE[i][0], BLUE[i][1]) = bridge;
        }
	
	}
    for (int i = 0; i < 32; i++) {
        image.at<Vec3b>(YELLOW[i][0], YELLOW[i][1]) = black;
    } 
	outputFile.close();
    cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
	resize(image, image, { 500, 500 }, 0 , 0 , cv::INTER_NEAREST);
	imshow("Image", image);
	waitKey(0);
    return 0;
}