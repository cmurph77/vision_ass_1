
//Part I.  Locate the table tennis ball.  Using colour, regions and shape locate table tennis balls and
// table tennis tables in the supplied images.  You can assume that the ball is either white or orange,
// may have some printing on it and will be spherical.  Ensure that you use techniques which can be
// used in general (e.g. ideally the techniques would cope with changes in lighting, etc.).  Analyse
// how well your approach works on the static images of the tables provided, and later on the table
// tennis video.  Note that in the report you may need to use some of the Learning and Evaluation
// section of the course, also in section 9.3 of “Computer Vision with OpenCV”  (when reporting performance).
#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "hsv_ball_identification.cpp"
using namespace cv;
using namespace std;


void find_center(int image_no){
    //cout<<"Finding the location of the ball in image" << image_no;
    string path = "/Users/cianmurphy/vision_ass_1/balls/Ball" + to_string(image_no) + ".jpg";  // TODO add a constant for the start of the path
    Mat ball_img = imread(path); // read in ball image from the path
    imshow("Ball" + to_string(image_no)+"  Image" ,ball_img);  // display original image

    /// ******* ENTER THE FUNCTION YOU WANT TO USE TO FIND BALL CENTER ***************
    pyimage_solution_white(ball_img);
}

void iterate_through_ball_images(){
    for (int i = 1; i < 5; ++i) {
        std::cout << "Image " << i << " ->";
        find_center(i);
    }
}



int main() {
    cout<<"Starting Program\n";
    iterate_through_ball_images();
    //find_center(2);
    waitKey(0);
    return 0;
}