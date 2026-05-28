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
                    { 151, 50} };

int BLUE[46][2] = {
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
{150, 46} };
int c = 0;
int d = 0;
int e = 0;
Vec3b black;
Vec3b bridge;
queue<pair<int, int>>future_RED;
queue<pair<int, int>>future_BLUE;
queue<pair<int, int>>future_YELLOW;
void moveX(Mat path, int shift);

int main() {
    cout << "Hello, World!" << endl;
    cout << "OpenCV version is " << CV_VERSION << endl;
    string imagePath = "C:/Users/yetam/source/repos/OpenCv/OpenCv/Screenshot.png";
    Mat image = imread(imagePath, IMREAD_COLOR);
    //   for (int i = 0; i < 15; i++)
     //  {
    int t1 = 10;
    moveX(image, t1);
    // }
    return 0;
}
void moveX(Mat image, int t1) {

    // outputFile.open("C:/Users/yetam/source/repos/OpenCv/OpenCv/output12.csv", ios::out | ios::app);
    // outputFile.close();

    // resize(image, image, { 500, 500 }, 0, 0, cv::INTER_NEAREST);
    imshow("Image", image);
    waitKey(500);
    // cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    for (int k = 0; k < t1; k++) {

        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);


        for (int i = 0; i < image.rows; ++i) {
            for (int j = 0; j < image.cols; ++j) {
                Vec3b pix = image.at<Vec3b>(i, j);
                if (i == 0 && j == 0)
                    black[0] = 0;
                black[1] = 0;
                black[2] = 0;

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

        for (int n = 0; n < 37; n++) {
            if (RED[n][1] < image.cols)
                image.at<Vec3b>(RED[n][0], RED[n][1]) = black;
        }
        for (int n = 0; n < 46; n++) {
            image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = black;
            if (n >= 37 && n <= 45)
            {
                image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = bridge;
            }

        }
        for (int n = 0; n < 32; n++) {
            if (YELLOW[n][1] < image.cols)
                image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = black;
        }

        for (int n = 0; n < 37; n++) {
            RED[n][1] = RED[n][1] + 15;
        }
        for (int n = 0; n < 124; n++) {
            BLUE[n][1] = BLUE[n][1] + 15;
        }

        c = 0;
        d = 0;
        e = 0;
        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
        // resize(image, image, { 500, 500 }, 0, 0, cv::INTER_NEAREST);
        imshow("Image", image);
        waitKey(1000);
    }
    //destroyWindow("Image History");
    //destroyWindow("Image");
}