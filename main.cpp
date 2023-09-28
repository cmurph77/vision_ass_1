#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////



Mat convert_to_binary(Mat original_image){
    Mat grayscale_image;//declaring a matrix to store grayscale image//
    Mat binary_image;//declaring a matrix to store the binary image
//    namedWindow("Original Image");//declaring window to show binary image//
//    namedWindow("Show Binary");//declaring window to show original image//
    cvtColor(original_image, grayscale_image, COLOR_BGR2GRAY);//Converting BGR to Grayscale image and storing it into converted matrix//
    threshold(grayscale_image, binary_image, 180, 255, THRESH_BINARY);//converting grayscale image stored in converted matrix into binary image//
    //imshow("Original Image", original_image);//showing Original Image//
    //imshow("Show Binary", binary_image);//showing Binary Image//
    return binary_image;
}

void find_letters(){
    string path = "/Users/cianmurphy/Desktop/OpenCV/images/yellow_sign.png";
    Mat original_image = imread(path);
    Mat grayscale_image;//declaring a matrix to store grayscale image//
    Mat binary_image;//declaring a matrix to store the binary image
    cvtColor(original_image, grayscale_image, COLOR_BGR2GRAY);//Converting BGR to Grayscale image and storing it into converted matrix//
    threshold(grayscale_image, binary_image, 100, 255, THRESH_BINARY);//converting grayscale image stored in converted matrix into binary image//
    imshow("Show Binary", binary_image);//showing Binary Image//
    //imshow("Original Image", original_image);//showing Original Image//


}

void get_ball_location(Mat img){

}

void part1(){
    cout<<"Finding the location of the ball in image 1";

}

int main() {
    part1();
    waitKey(0);
    return 0;
}