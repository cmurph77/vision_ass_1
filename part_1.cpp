// This C++ code utilizes the OpenCV library to perform the following operations on an input image:
//
//Load an image.
//Convert the image to grayscale.
//Blur the grayscale image using a 3x3 kernel.
//Apply the Hough Circle Transform to detect circles in the blurred grayscale image.
//Draw the detected circles on the original color image:
//Circumference of the detected circles in green.
//Centers of the detected circles in red.
//Display the image with the detected circles.
//The Hough Circle Transform is used to identify circles in the image, and the detected circles are then
// visualized on the original image to illustrate the detected features.

void edge_detection(Mat img){
    //std:cout << "doing edge detection";
    imshow("origninal image",img);

    // Convert to grayscale
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // Blur using a 3x3 kernel
    cv::Mat grayBlurred;
    int blur_matrix = 10;
    cv::blur(gray, grayBlurred, cv::Size(blur_matrix, blur_matrix));

    // Apply Hough transform on the blurred image
    int maxBallRadius = 100;
    int minDist = grayBlurred.rows / 8;
    std::vector<cv::Vec3f> detectedCircles;
    cv::HoughCircles(grayBlurred, detectedCircles, cv::HOUGH_GRADIENT, 1,
                     minDist,  // change this value to detect circles with different distances to each other
                     50, 30, 1, maxBallRadius);

    // Draw circles that are detected
    for (size_t i = 0; i < detectedCircles.size(); i++){
        //std::cout << "Circles Detected";
        cv::Point center(cvRound(detectedCircles[i][0]), cvRound(detectedCircles[i][1])); // firse two vals in circle vector is corrds
        int radius = cvRound(detectedCircles[i][2]); // third value is radius

        // Draw the circumference of the circle
        cv::circle(img, center, radius, cv::Scalar(0, 255, 0), 2);

        // Draw a small circle (of radius 1) to show the center
        cv::circle(img, center, 1, cv::Scalar(0, 0, 255), 3);
        std::cout << ": (" << center.x << ", " << center.y << ")" << std::endl;

    }
    cv::imshow("Detected Circles", img);

}
void find_center(int image_no){
    //cout<<"Finding the location of the ball in image" << image_no;
    string path = "/Users/cianmurphy/code_directories/vision_ass_1/balls/Ball" + to_string(image_no) + ".jpg";  // TODO add a constant for the start of the path
    Mat ball_img = imread(path); // read in ball image from the path
    imshow("Ball " + to_string(image_no)+"  Image" ,ball_img);  // display original image

    /// ******* ENTER THE FUNCTION YOU WANT TO USE TO FIND BALL CENTER ***************
    //clustering_attempt(ball_img);
    edge_detection(ball_img);

}

void iterate_through_ball_images(){
    for (int i = 1; i < 10; ++i) {
        std::cout << "Image " << i << "";
        find_center(i);
    }
}

void part_1(){
    //todo back project the circle and verify if white or orange?
    iterate_through_ball_images();
    //find_center(8);

}