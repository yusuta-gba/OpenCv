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
int maximumSpace[115][2];
int c = 0;
int d = 0;
int e = 0;
Vec3b black;
Vec3b bridge;
Vec3b futureBox1[37], futureBox2[46], futureBox3[32];
Vec3b temp[115];
Vec3b futureBox4[115];
Vec3b pastBox5[115];
vector<Vec3b> memory;
int memoryIndex = 0;
bool firstMV_R = true;
bool firstMV_B = true;
bool firstMV_Y = true;
bool firstMV_LADDER = true;
bool first_MAXIMUM = true;
bool first_backwards = true;
bool climb = false;
void maximum(bool x, bool y, bool init);
void play(Mat path, int shift);
void play2(Mat path, int shift);
void moveX(Mat path, int shift, int times);
void moveY(Mat path, int shift, int times);
void backwards(Mat path, int shift, int times);
void rotate(Mat image, bool direction);
void rotate2(Mat image);
void display(Mat path, int freq);
void scan(Mat path);
void getDeletor();
int main() {
    string imagePath = "C:/Users/yetam/source/repos/OpenCv/OpenCv/Screenshot.png";
    Mat image = imread(imagePath, IMREAD_COLOR);
    //  scan(image);
    maximum(true,false, true);
    play2(image, 10);
    //    scan(image);
   
    return 0;
}
/*
* Just displaying the image.
*/
void rotateCap(Mat image)
{

    maximum(false, true, false);
    int min = maximumSpace[114][0];
    int index = -1;
    Vec3b temp3[115];
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    for (int k = 0; k < 115; k++)
    {
        temp3[k] = image.at<Vec3b>(maximumSpace[k][1], maximumSpace[k][0]);
    }
    for (int i = 114; i >= 0; i--)
    {
        ofstream outputFile;
        outputFile.open("C:/Users/yetam/source/repos/OpenCv/OpenCv/coordinate.csv", ios::out | ios::app);
        outputFile << "index: " << i << " x: " << maximumSpace[i][0] << " y: " << maximumSpace[i][1] << endl;
        outputFile.close();       
    }
    for (int i = 114; i >= 103; i--)
    {
        if (maximumSpace[i][0] < min)
        {
            min = maximumSpace[i][0];
            index = i;
        }
    }
    int counter = 1;
    for (int i = 114; i >= 111; i--)
    {
        maximumSpace[i][0] = min - counter - 3;
        counter++;
    }
    maximumSpace[110][0] = min -3;
    counter = 1;
    for (int i = 109; i >= 103; i--)
    {
        maximumSpace[i][0] = min - counter - 3;
        counter++;
    }
    counter = 3;
    for (int i = 102; i >= 97; i--)
    {
        maximumSpace[i][0] = min - counter;
        counter++;
    }
    counter = 3;
    for (int i = 96; i >= 87; i--)
    {
        maximumSpace[i][0] = min - counter + 1;
        counter++;
    }
    counter = 3;
    for (int i = 86; i > 75; i--)
    {
      
        maximumSpace[i][0] = min - counter + 1;
        counter++;
    }

    counter = 3;
    for (int i = 75; i > 64; i--)
    {
        maximumSpace[i][0] = min - counter + 1 + 1;
        counter++;
    }
    counter = 4;
    for (int i = 64; i > 55; i--)
    {
        maximumSpace[i][0] = min - counter + 1 + 1;
        counter++;
    }
    counter = 3;
    for (int i = 55; i > 47; i--)
    {
        maximumSpace[i][0] = min - counter + 1;
        counter++;
    }
    counter = 3;
    for (int i = 47; i > 38; i--)
    {
        maximumSpace[i][0] = min - counter + 1;
        counter++;
    }
    counter = 3;
    for (int i = 38; i > 29; i--)
    {
        maximumSpace[i][0] = min - counter + 1;
        counter++;
    }
    counter = 3;
    for (int i = 29; i > 20; i--)
    {
        maximumSpace[i][0] = min - counter + 1;
        counter++;
    }
    counter = 3;
    
    for (int i = 20; i > 16; i--)
    {
        maximumSpace[i][0] = min - counter;
        counter++;
    } 
    counter++;
    for (int i = 16; i > 13; i--)
    {
        maximumSpace[i][0] = min - counter;
        counter++;
    }
   
    for (int i = 13; i > 9; i--)
    {
        if (i == 12)
        {
            maximumSpace[i][1] = maximumSpace[i][1] - 1;
            continue;
        }
        maximumSpace[i][0] = min - counter + 8;
        counter++;
    }
    counter++;
    counter++;
    for (int i = 9; i > 6; i--)
    {
        maximumSpace[i][0] = min - counter + 8;
        counter++;
    }


       counter = 3;
    for (int i = 6; i >= 3; i--)
    {
        maximumSpace[i][0] = min - counter;
        counter++;
    }
      
    for (int i = 2; i >= 0; i--)
    {
        maximumSpace[i][0] = min - counter - 2;
        counter++;
    }

    for (int k = 0; k < 115; k++)
    {
        image.at<Vec3b>(maximumSpace[k][1], maximumSpace[k][0]) = temp3[k];
    }
    display(image, 50);
}
void backwards(Mat image)
{
    Vec3b temp3[115];
    for (int j = 0; j < 12; j++)
    {
        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
        for (int k = 0; k < 115; k++)
        {
            temp3[k] = image.at<Vec3b>(maximumSpace[k][1], maximumSpace[k][0]);
        }
        for (int i = 0; i < 115; i++)
        {
          //  temp[i] = image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]);
            if (first_backwards)
            {
                image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]) = futureBox4[i];
            }
            else 
            {
                image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]) = futureBox4[i];
            }
            

        }
        for (int i = 0; i < 115; i++)
        {
            maximumSpace[i][0] = maximumSpace[i][0] - 1;
            futureBox4[i] = image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]);
            image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]) = temp3[i];
        }
       
       
     
            first_backwards = false;
            cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
    }


}
void moveX2(Mat image, int shift, int times, bool climb)
{
  
    
        for (int j = 0; j < times; j++)
        {
            cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
            for (int i = 0; i < 115; i++)
            {
                temp[i] = image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]);
                if (first_MAXIMUM)
                {
                    image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]) = black;
                }
                else
                {
                    if (shift > 0)
                    {
                        image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]) = futureBox4[i];

                    }

                }
                maximumSpace[i][0] = maximumSpace[i][0] + shift;
                futureBox4[i] = image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]);
                image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]) = temp[i];

            }

            first_MAXIMUM = false;
            
            display(image, 1);
        }
    
   
}
void moveY2(Mat image, int shift, int times, bool climb)
{
    int maximumSpace2[115];
    Vec3b startClimbing[115];
    Vec3b temp2[115];
 //   maximum(false, true, false);
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    for (int i = 0; i < 115; i++)
    {
       // maximumSpace2[i] = maximumSpace[i][1];
        startClimbing[i] = image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]);
    }

    for (int j = 0; j < times; j++)
    {
      //  cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
        for (int i = 0; i < 115; i++)
        {
            maximumSpace2[i] = maximumSpace[i][1];
            temp2[i] = image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]);
        }
        for (int i = 0; i < 115; i++)
        {
          //  if(maximumSpace[i][1] != 153)
                image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]) = futureBox4[i];
               
            maximumSpace[i][1] = maximumSpace[i][1] - 1;
        
        }
        for (int i = 0; i < 115; i++)
        {
            futureBox4[i] = image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]);
        }
        for (int i = 0; i < 115; i++)
        {
            image.at<Vec3b>(maximumSpace[i][1], maximumSpace[i][0]) = temp2[i];
        }
        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
      // first_MAXIMUM = false;
       // if(climb != false)
       // display(image, 1);
     //   maximum(true, false, false);
      //  moveX2(image, 1, 12, true);
      //  backwards(image);
       // display(image, 50);
       // moveX2(image, -1, 12);
      //  while (true);
    }

}
void display(Mat image, int freq) {
    cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
    imshow("Image", image);
    waitKey(freq);
}
/*
*
* Just moving the pixels with the specific colors in the x direction 
*/
void moveX(Mat image, int shift, int times) {
    Vec3b red[37], blue[46], yellow[32];
    bridge = Vec3b(255, 66, 107);
    for (int i = 0; i < times; i++)
    {
        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
        for (int n = 0; n < 37; n++) {
            red[n] = image.at<Vec3b>(RED[n][0], RED[n][1]);

            if (!firstMV_R)
            {
				image.at<Vec3b>(RED[n][0], RED[n][1]) = futureBox1[n];
            }
            else
            {
                image.at<Vec3b>(RED[n][0], RED[n][1]) = black;
				if (n == 36)
                firstMV_R = false;
            }
            futureBox1[n] = image.at<Vec3b>(RED[n][0], RED[n][1] + shift);
            RED[n][1] = RED[n][1] + shift;
        //    if(climb)
         //       RED[n][0] = RED[n][0] - 1;
            image.at<Vec3b>(RED[n][0], RED[n][1]) = red[n];

        }
        for (int n = 0; n < 46; n++) {
            blue[n] = image.at<Vec3b>(BLUE[n][0], BLUE[n][1]);
           
            if (!firstMV_B)
            {
				image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = futureBox2[n];
            }
            else
            {
                image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = black;
                if(n == 45)
                firstMV_B = false;
            }
            futureBox2[n] = image.at<Vec3b>(BLUE[n][0], BLUE[n][1] + shift);
            if (n >= 37 && n <= 45)
            {
                if (BLUE[n][0] > 0)
                    image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = bridge;
            }
            BLUE[n][1] = BLUE[n][1] + shift;
         //   if (climb)
          //      BLUE[n][0] = BLUE[n][0] - 1;
            image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = blue[n];

        }
        for (int n = 0; n < 32; n++) {
            yellow[n] = image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]);
            
            if (!firstMV_Y)
            {
				image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = futureBox3[n];
            }
            else
            {
                image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = black;
                if (n == 31)
                firstMV_Y = false;
            }
            futureBox3[n] = image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1] + shift);
            YELLOW[n][1] = YELLOW[n][1] + shift;
         //   if (climb)
         //       YELLOW[n][0] = YELLOW[n][0] - 1;
            image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = yellow[n];
        }
		display(image,300);
    }
}
/*
*
* Just moving the pixels with the specific colors in the y direction.
*/
void moveY(Mat image, int shift)
{

	Vec3b red[37], blue[46], yellow[32];
    for (int n = 0; n < 37; n++) {
        red[n] = image.at<Vec3b>(RED[n][0], RED[n][1]);
        if (!firstMV_R)
        {
            image.at<Vec3b>(RED[n][0], RED[n][1]) = futureBox1[n];
        }
        else
        {
            image.at<Vec3b>(RED[n][0], RED[n][1]) = black;
            if (n == 36)
                firstMV_R = false;
        }
        //image.at<Vec3b>(RED[n][0], RED[n][1]) = black;
        
        RED[n][0] = RED[n][0] - shift;
        image.at<Vec3b>(RED[n][0], RED[n][1]) = red[n];

    }
    for (int n = 0; n < 46; n++) {
        blue[n] = image.at<Vec3b>(BLUE[n][0], BLUE[n][1]);
        if (!firstMV_B)
        {
            image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = futureBox2[n];
        }
        else
        {
            image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = black;
            if (n == 45)
                firstMV_B = false;
        }
        if (n >= 37 && n <= 45)
        {
            if (BLUE[n][0] > 0)
                image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = bridge;
        }

        BLUE[n][0] = BLUE[n][0] - shift;
        image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = blue[n];

    }
    for (int n = 0; n < 32; n++) {
        yellow[n] = image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]);
        if (!firstMV_Y)
        {
            image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = futureBox3[n];
        }
        else
        {
            image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = black;
            if (n == 31)
                firstMV_Y = false;
        }
       // image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = black;
        YELLOW[n][0] = YELLOW[n][0] -  shift;
        image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = yellow[n];

    }
    firstMV_R = true;
    firstMV_B = true;
    firstMV_Y = true;
    climb = true;
}
/*
 *  Just moving the pixels with the specific colors in the x direction by the specific amounts to create a rotation effect.
 *
 */
void rotate(Mat image, bool direction)
{
	Vec3b red[37], blue[46], yellow[32];
    bridge = Vec3b(255, 66, 107);
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
           if(direction)
                RED[n][1] = RED[n][1] + diff_RED_x[n];
           else
                RED[n][1] = RED[n][1] - diff_RED_x[n];
            image.at<Vec3b>(RED[n][0], RED[n][1]) = red[n];
        }
        for (int n = 0; n < 46; n++) {
             if(direction)
                BLUE[n][1] = BLUE[n][1] + diff_BLUE_x[n];
             else
				 BLUE[n][1] = BLUE[n][1] - diff_BLUE_x[n];
            image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = blue[n];
            if (n >= 37 && n <= 45)
            {
                image.at<Vec3b>(BLUE[n][0], BLUE[n][1]) = bridge;
            }
        }
        for (int n = 0; n < 32; n++) {
            if(direction)
                YELLOW[n][1] = YELLOW[n][1] + diff_YELLOW_x[n];
            else
				YELLOW[n][1] = YELLOW[n][1] - diff_YELLOW_x[n];
            image.at<Vec3b>(YELLOW[n][0], YELLOW[n][1]) = yellow[n];
        }

    }
}
/*
 *
 *  Just scanning the image and writing the x coordinates of the pixels with the specific colors to csv files.
 * 
 * 
 */
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


void play(Mat image, int t1) {

    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    display(image,300);
    waitKey(500);
	moveX(image, 15, 10); // move right 15 pixels 10 times
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
	moveY(image, 21);    // move up 21 pixels
    display(image, 300);
	rotate(image, true); // rotate right
    display(image, 300);
	moveX(image, -15, 6); // move left 15 pixels 6 times
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
	moveY(image, 23); // move up 23 pixels
    display(image, 300); 
	rotate(image, false); // rotate left
    display(image, 300); 
	moveX(image, 15, 1); // move right 15 pixels 1 time
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
	moveY(image, 26); // move up 26 pixels
	display(image, 300); 
	rotate(image, true); // rotate right
	display(image, 300); 
	moveX(image, -18, 2); // move left 18 pixels 2 times
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
	moveY(image, 20);
    display(image, 300); 
	rotate(image, false); // rotate left
	display(image, 300); 
	moveX(image, 16, 7); // move right 16 pixels 7 times
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
	moveY(image, 20); //   
    display(image, 300);     
	rotate(image, true); // rotate right
    display(image, 300);     
	moveX(image, -19, 3); // move left 19 pixels 3 times
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
	moveY(image, 20); //    
    display(image, 300);         
	moveX(image, -15, 2); // move left 15 pixels 2 times
	cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
	//display(image);
    destroyWindow("Image");
    return;
}
void play2(Mat image, int shift)
{
    cout << "PLAY GOING ON" << endl;
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    display(image, 300);
 //   waitKey(20000);
    moveX2(image, 1, 150, false); 
    backwards(image);
    for (int i = 0; i < 20; i++)
    {
        moveY2(image, 1, 1, true);
        moveX2(image, 12, 1,true);
        backwards(image);
    }
    rotateCap(image);

        while (true);
   
   
}
void maximum(bool x, bool y, bool initialize) {

    int globalCounter = 0;
    if (initialize)
    {
        for (int i = 0; i < 37; i++)
        {
            maximumSpace[globalCounter++][0] = RED[i][1];
            maximumSpace[globalCounter - 1][1] = RED[i][0];
        }
        for (int i = 0; i < 46; i++)
        {
            maximumSpace[globalCounter++][0] = BLUE[i][1];
            maximumSpace[globalCounter - 1][1] = BLUE[i][0];
        }
        for (int i = 0; i < 32; i++)
        {
            maximumSpace[globalCounter++][0] = YELLOW[i][1];
            maximumSpace[globalCounter - 1][1] = YELLOW[i][0];
        }
    }
    while (true)
    {
        if (x == true)
        {
            int counter = 0;
            bool breakFlag = false;
            for (int i = 0; i < 115; i++)
            {
                if (maximumSpace[i][0] < maximumSpace[i + 1][0])
                {
                    int temp = maximumSpace[i + 1][0];
                    maximumSpace[i + 1][0] = maximumSpace[i][0];
                    maximumSpace[i][0] = temp;
                    int temp2 = maximumSpace[i + 1][1];
                    maximumSpace[i + 1][1] = maximumSpace[i][1];
                    maximumSpace[i][1] = temp2;

                }
                else
                {
                    counter++;
                    if (counter == 114)
                    {
                        breakFlag = true;
                    }
                }

            }
            if (breakFlag == true)
            {
                break;
            }
        }
        else if(y == true)
        {
            int counter = 0;
            bool breakFlag = false;
            for (int i = 0; i < 115; i++)
            {
                if (maximumSpace[i][1] < maximumSpace[i + 1][1])
                {
                    int temp = maximumSpace[i + 1][1];
                    maximumSpace[i + 1][1] = maximumSpace[i][1];
                    maximumSpace[i][1] = temp;
                    int temp2 = maximumSpace[i + 1][0];
                    maximumSpace[i + 1][0] = maximumSpace[i][0];
                    maximumSpace[i][0] = temp2;

                }
                else
                {
                    counter++;
                    if (counter == 114)
                    {
                        breakFlag = true;
                    }
                }

            }
            if (breakFlag == true)
            {
                break;
            }
        }
    }

    if (y == true)
    {
        for (int i = 0; i < 115; i++)
        {
            cout << i << ". " << maximumSpace[i][1] << endl;
        }
     
    }
   
}
	
	

