
//Part I.  Locate the table tennis ball.  Using colour, regions and shape locate table tennis balls and
// table tennis tables in the supplied images.  You can assume that the ball is either white or orange,
// may have some printing on it and will be spherical.  Ensure that you use techniques which can be
// used in general (e.g. ideally the techniques would cope with changes in lighting, etc.).  Analyse
// how well your approach works on the static images of the tables provided, and later on the table
// tennis video.  Note that in the report you may need to use some of the Learning and Evaluation
// section of the course, also in section 9.3 of “Computer Vision with OpenCV”  (when reporting performance)

//Part II. Locate the table tennis table.  You must now locate the corners of the table (the outside of the
// white lines) using edge detection, and then transform the image so that you have a plan view of the table.
// Determine how well your approach works on the static images of the tables provided. Ensure that you use
// techniques which can be used in general (e.g. ideally the techniques would cope with changes in lighting, etc.).
// Analyse how well your approach works on the static images of the tables provided, and later on the table tennis
// video.  Note that in the report you may need to use some of the Learning and Evaluation section of the course,
// also in section 9.3 of “Computer Vision with OpenCV”  (when reporting performance).

#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "hsv_ball_identification.cpp"
#include "clustering_attempt.cpp"
#include "part_1.cpp"
using namespace cv;
using namespace std;



int main() {
    cout<<"Starting Program..\n";
    //iterate_through_ball_images();
    part_1();
    waitKey(0);
    return 0;
}