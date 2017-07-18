
#include <opencv2/highgui.hpp>
#include <highgui.h>
#include <cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
        double alpha = 0.5; double beta; double input;
        Mat src1, src2, dst;
        //matrix src1, src2 and dst
        cout << "Simple Linea Blender"<< endl;
        cout << "---------------------"<<endl;
        cout << "* Enter alpha[0-1]:";
        cin >> input;
        if(input >=0.0 && input <=1.0){
                alpha = input;
        }       
        src1 = imread("/home/security/project/opencv2.1/.....jpg");
        src2 = imread("/home/security/project/opencv2.1/.....jpg");
        //the photos should have same size and format
        if(!src1.data){printf("error loading src1 \n"); return -1;}
        if(!src2.data){printf("error loading src2 \n"); return -1;}
         
        namedWindow("Linear Blend", 1);
        beta = (1.0 - alpha);
        addWeighted(src1, alpha, src2, beta, 0.0, dst);
        imshow("Linear Blend", dst);
        waitKey(0);
        return 0;
}
