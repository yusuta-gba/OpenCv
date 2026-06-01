#include <vector>
#include <array>
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

//vector<std::array<int, 2>> RED(37), BLUE(124), YELLOW(32);
int diff_RED_x[37] = {  
    0, 0, 0, 0, -2, -2, -2, -2,
   -2, -2, -2, -2, -7, -5, -5,
   -5, -5, -5, -1, -5, -5, -5,
   -1, -1, -1, -3, -3, -3, -1,
   -1,  0,  0, 0,  1,  0,  0,
    0,

};
	

int diff_BLUE_x[46] = { 2, 2, 2, 2, 1, 1, 1, 0, 0,
                        0, 0, -1, -1, -1, -5, -1, -1, -1,
                        6, 6, 1, 1, 1, 1, 1, 1, 1, 4, 4,
                        4, 4, 5, 0, 0, 0, 0, 0, 0, -1, -1,
                        -1,-1, -1,-1, -1, -1,

};
int diff_YELLOW_x[32] = { 
    -4, -4, -3, -3, -4, -3, -4, -3,
-3, -4, -4, -6, -5, -6, -4, -4,
0, 0, 0, 0, -3, -3, -3, -3,
-3, -3, -3, 1, 1, 1, 2, 2,
};
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
void moveXY(Mat path, int shift);
void scan(Mat path);

int main() {
    cout << "Hello, World!" << endl;
    string imagePath = "C:/Users/yetam/source/repos/OpenCv/OpenCv/Screenshot.png";
    Mat image = imread(imagePath, IMREAD_COLOR);
  //  scan(image);
    moveXY(image, 10);
//    scan(image);
    return 0;
}
void scan(Mat path) {
	 c = 0;
     d = 0;
     e = 0;
    cv::cvtColor(path, path, cv::COLOR_BGR2RGB);
    printf("DOWN");
//	outputFile << "COLOR,ROW,COL" << endl; 
	for (int i = 0; i < path.rows; ++i) {
		for (int j = 0; j < path.cols; ++j) {
			Vec3b pix = path.at<Vec3b>(i, j);
            int r = pix[0], g = pix[1], b = pix[2];
			cout << r << " " << g << " " << b << endl;
			if (r == 255 && g == 66 && b == 41)
			{
                if (i == RED[c][0] && j == RED[c][1]) {
                    c++;

                    ofstream outputFile;
                    outputFile.open("C:/Users/yetam/source/repos/OpenCv/OpenCv/RED_x.csv", ios::out | ios::app);
                    outputFile << to_string(j) << "," << endl;
                    outputFile.close();

                }

			}
			if (r == 82 && g == 33 && b == 222)
			{

                if (i == BLUE[d][0] && j == BLUE[d][1])
                {
                    d++;



                    ofstream outputFile;
                    outputFile.open("C:/Users/yetam/source/repos/OpenCv/OpenCv/BLUE_x.csv", ios::out | ios::app);
                    outputFile << to_string(j) << endl;
                    outputFile.close();
                }
			}
            if (r == 255 && g == 222 && b == 181)
            {

                if (i == YELLOW[e][0] && j == YELLOW[e][1])
                {
                    e++;




                    ofstream outputFile;
                    outputFile.open("C:/Users/yetam/source/repos/OpenCv/OpenCv/YELLOW_x.csv", ios::out | ios::app);
                    outputFile << to_string(j) << endl;
                    outputFile.close();
                }
            }
		//		outputFile  << "YELLOW:" + i + "," + j << endl;
			}
		}
    return;
}
	//outputFile.close();


void moveXY(Mat image, int t1) {
//	ofstream outputFile;
 //   outputFile.open("C:/Users/yetam/source/repos/OpenCv/OpenCv/opencv31.csv", ios::out | ios::app);
    // outputFile.close();

    // resize(image, image, { 500, 500 }, 0, 0, cv::INTER_NEAREST);
    imshow("Image", image);
    waitKey(500);
    // cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    for (int k = 0; k < 10; k++) {

        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
        //	cout << image.rows << " " << image.cols << endl;

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
                    if (c < 37 &&
                        RED[c][0] >= 0 && RED[c][0] < image.rows &&
                        RED[c][1] >= 0 && RED[c][1] < image.cols) {
                        if (i == RED[c][0] && j == RED[c][1]) {

                            c++;
                            if (j + 15 < image.cols) {
                                image.at<Vec3b>(i, j + 15) = pix;
                            }
                        }
                    }

                }


                if (r == 82 && g == 33 && b == 222)
                {
                    if (d < 46 &&
                        BLUE[c][0] >= 0 && BLUE[c][0] < image.rows &&
                        BLUE[c][1] >= 0 && BLUE[c][1] < image.cols) {
                        if (i == BLUE[d][0] && j == BLUE[d][1])
                        {
                            d++;
                            if (j + 15 < image.cols) {
                                image.at<Vec3b>(i, j + 15) = pix;
                            }

                        }
                    }
                }

                if (r == 255 && g == 222 && b == 181)
                {
                    if (e < 32 &&
                        YELLOW[c][0] >= 0 && YELLOW[c][0] < image.rows &&
                        YELLOW[c][1] >= 0 && YELLOW[c][1] < image.cols) {
                        if (i == YELLOW[e][0] && j == YELLOW[e][1])
                        {
                            e++;
                            if (j + 15 < image.cols) {
                                image.at<Vec3b>(i, j + 15) = pix;
                            }

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
        for (int n = 0; n < 46; n++) {
            BLUE[n][1] = BLUE[n][1] + 15;
        }
        for (int n = 0; n < 32; n++) {
            YELLOW[n][1] = YELLOW[n][1] + 15;
        }

        c = 0;
        d = 0;
        e = 0;
        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
        // resize(image, image, { 500, 500 }, 0, 0, cv::INTER_NEAREST);
        imshow("Image", image);
        waitKey(500);
    }
    
    for (int k = 0; k < 1; k++) {

        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);

        //	cout << "Y-AXIS SHIFT: "  << endl;
        for (int i = 0; i < image.rows; ++i) {
            for (int j = 0; j < image.cols; ++j) {
                Vec3b pix = image.at<Vec3b>(i, j);
                if (i == 0 && j == 0)
                    black[0] = 0;
                black[1] = 0;
                black[2] = 0;

                int r = pix[0], g = pix[1], b = pix[2];
                //   cout << "FILTRATION" << endl;
                 //  cout << image.rows << " " << image.cols << endl;

                if (r == 255 && g == 66 && b == 41)
                {

                    if (i == RED[c][0] && j == RED[c][1]) {
                        c++;
                        if (i > 0) {
                            image.at<Vec3b>(i - 21, j) = pix;

                        }
                    }


                }


                if (r == 82 && g == 33 && b == 222)
                {

                    if (i == BLUE[d][0] && j == BLUE[d][1])
                    {
                        d++;
                        if (i > 0) {
                            image.at<Vec3b>(i - 21, j) = pix;

                        }

                    }
                }

                if (r == 255 && g == 222 && b == 181)
                {
                    if (i == YELLOW[e][0] && j == YELLOW[e][1])
                    {
                        e++;
                        if (i > 0) {
                            image.at<Vec3b>(i - 21, j) = pix;

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
            //            if (RED[n][0] < image.rows)
                 //           image.at<Vec3b>(RED[n][0], RED[n][1]) = black;
        }
        for (int n = 0; n < 46; n++) {
            if (BLUE[n][0] > 0)
                image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = black;
            if (n >= 37 && n <= 45)
            {
                if (BLUE[n][0] > 0)
                    image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = bridge;
            }

        }
        for (int n = 0; n < 32; n++) {
            if (YELLOW[n][0] > 0)
                image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = black;
        }

        for (int n = 0; n < 37; n++) {
            RED[n][0] = RED[n][0] - 21;
		//	outputFile << "RED:" + to_string(RED[n][0]) + "," + to_string(RED[n][1]) << endl;
        }
        for (int n = 0; n < 46; n++) {
            BLUE[n][0] = BLUE[n][0] - 21;
		//	outputFile << "BLUE:" + to_string(BLUE[n][0]) + "," + to_string(BLUE[n][1]) << endl;
        }
		for (int n = 0; n < 32; n++) {
			YELLOW[n][0] = YELLOW[n][0] - 21;
		//	outputFile << "YELLOW:" + to_string(YELLOW[n][0]) + "," + to_string(YELLOW[n][1]) << endl;
		}

        c = 0;
        d = 0;
        e = 0;
        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
        // resize(image, image, { 500, 500 }, 0, 0, cv::INTER_NEAREST);
        imshow("Image", image);
        waitKey(500);
    } 
    //  waitKey();
   // destroyWindow("Image");
//    outputFile.close();
	Vec3b red[37];
	Vec3b blue[46];
	Vec3b yellow[32];
    
    for (int k = 0; k < 1; k++) {

        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);

        for (int n = 0; n < 37; n++) {
            if (RED[n][1] < image.cols)
                red[n] = image.at<Vec3b>(RED[n][0], RED[n][1]);
            image.at<Vec3b>(RED[n][0], RED[n][1]) = black;
        }
        for (int n = 0; n < 46; n++) {
            blue[n] = image.at<Vec3b>(BLUE[n][0], BLUE[n][1]);
            image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = black;
            if (n >= 37 && n <= 45)
            {
                image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = bridge;
            }

        }
        for (int n = 0; n < 32; n++) {
            if (YELLOW[n][1] < image.cols)
            {
                yellow[n] = image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]);
                image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = black;

            }
        }
        for (int n = 0; n < 37; n++) {
            RED[n][1] = RED[n][1] + diff_RED_x[n];
            image.at<Vec3b>(RED[n][0], RED[n][1]) = red[n];
        }
        for (int n = 0; n < 46; n++) {
            BLUE[n][1] = BLUE[n][1] + diff_BLUE_x[n];
            image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = blue[n];
            if (n >= 37 && n <= 45)
            {
                image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = bridge;
            }
        }
        for (int n = 0; n < 32; n++) {
            YELLOW[n][1] = YELLOW[n][1] + diff_YELLOW_x[n];
            image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = yellow[n];
        }





    }

        c = 0;
        d = 0;
        e = 0;
        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
        // resize(image, image, { 500, 500 }, 0, 0, cv::INTER_NEAREST);
        imshow("Image", image);
       waitKey(500);
   

        destroyWindow("Image");
        return; }