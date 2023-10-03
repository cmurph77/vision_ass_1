
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
using namespace cv;
using namespace std;


void gpt_solution(Mat image){
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // Perform circle detection
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(grayImage, circles, cv::HOUGH_GRADIENT, 1,
                     grayImage.rows / 8,  // change this value to detect circles with different distances to each other
                     100, 30, 10, 50);    // change the last two parameters (min_radius & max_radius) to detect circles of different sizes

    // Check if circles were found
    if (!circles.empty()) {
        // Draw the detected circle
        cv::Vec3i circle = circles[0];
        cv::Point center(circle[0], circle[1]);
        int radius = circle[2];

        // Calculate the diameter
        float diameter = 2.0f * radius;

        cv::circle(image, center, radius, cv::Scalar(0, 0, 255), 2);  // Draw the circle
        cv::circle(image, center, 3, cv::Scalar(0, 255, 0), -1);      // Draw the center of the circle

        // Print the circle information
        std::cout << "Center coordinates (x, y): (" << circle[0] << ", " << circle[1] << ")\n";
        std::cout << "Diameter: " << diameter << std::endl;
    } else {
        std::cerr << "No circles were detected." << std::endl;
    }

    // Display the image
    cv::imshow("Circle Detection", image);
}

// this program curerntly only solves for 1 orange ball
void pyimage_solution(Mat image){

    // Define the green color range
    cv::Scalar orangeLower(15,100,100);
    cv::Scalar orangeUpper(30,255,255);

    // Load the frame (assuming it's already loaded in Python)
    cv::Mat frame = image;  // Load your frame using cv::imread in actual usage

    // Resize the frame
    //cv::resize(frame, frame, cv::Size(600, frame.rows * 600 / frame.cols));

    // Apply Gaussian blur
    cv::GaussianBlur(frame, frame, cv::Size(11, 11), 0);

    // Convert to HSV color space
    cv::Mat hsv;
    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

    // Create a mask for the green color
    cv::Mat mask;
    cv::inRange(hsv, orangeLower, orangeUpper, mask);

    // Perform dilations and erosions on the mask
    cv::erode(mask, mask, cv::Mat(), cv::Point(-1, -1), 2);
    cv::dilate(mask, mask, cv::Mat(), cv::Point(-1, -1), 2);

    // Further processing with the mask...
    //imshow("mask", mask);
    // (Perform actions with the mask as needed in your application)

    // Find contours in the mask
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask.clone(), contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Initialize the current (x, y) center of the ball
    cv::Point2f center;

    // Only proceed if at least one contour was found
    if (!contours.empty()) {
        // Find the largest contour in the mask
        auto c = *std::max_element(contours.begin(), contours.end(),
                                   [](const std::vector<cv::Point>& a, const std::vector<cv::Point>& b) {
                                       return cv::contourArea(a) < cv::contourArea(b);
                                   });

        // Compute the minimum enclosing circle and centroid
        cv::Point2f center;
        float radius;
        cv::minEnclosingCircle(c, center, radius);

        cv::Moments M = cv::moments(c);
        center = cv::Point2f(M.m10 / M.m00, M.m01 / M.m00);

        // Only proceed if the radius meets a minimum size
        if (radius > 10) {
            // Draw the circle and centroid on the frame (assuming it's already loaded)

            cv::circle(frame, center, static_cast<int>(radius), cv::Scalar(0, 255, 255), 2);
            cv::circle(frame, center, 5, cv::Scalar(0, 0, 255), -1);
        }
        // Print the center coordinates
        std::cout << "Center coordinates: (" << center.x << ", " << center.y << ")" << std::endl;
    }


}

void find_center(int image_no){
    //cout<<"Finding the location of the ball in image" << image_no;
    string path = "/Users/cianmurphy/vision_ass_1/balls/Ball" + to_string(image_no) + ".jpg";  // TODO add a constant for the start of the path
    Mat ball_img = imread(path); // read in ball image from the path
    //imshow("Ball" + to_string(image_no)+"  Image" ,ball_img);  // display original image
    //get_ball_location(ball_img);
    //gpt_solution(ball_img);
    pyimage_solution(ball_img);
}

void iterate_through_ball_images(){
    for (int i = 7; i < 11; ++i) {
        std::cout << "Image " << i << " ->";
        find_center(i);
    }
}



int main() {
    cout<<"Starting Program\n";
    //part1();
    iterate_through_ball_images();
    waitKey(0);
    return 0;
}