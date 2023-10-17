
bool isColorOrange(cv::Mat hsv_color) {
    // Define the lower and upper bounds for the orange color in HSV space
    cv::Scalar orangeLower(15, 100, 100);  // Lower bound for orange in HSV
    cv::Scalar orangeUpper(30, 255, 255);  // Upper bound for orange in HSV

    // Create an empty mask image of the same size as the input HSV image
    cv::Mat mask(hsv_color.size(), CV_8U);

    // Check if the provided HSV color is within the specified range for orange
    cv::inRange(hsv_color, orangeLower, orangeUpper, mask);

    // Check if any pixel is in the range (i.e., if any pixel in the mask is non-zero)
    return cv::countNonZero(mask) > 0;
}

bool isColorWhite(cv::Mat hsv_color) {
    // Define the lower and upper bounds for the orange color in HSV space
    cv::Scalar whiteLower(0,0,200);
    cv::Scalar whiteUpper(180,100,255);

    // Create an empty mask image of the same size as the input HSV image
    cv::Mat mask(hsv_color.size(), CV_8U);

    // Check if the provided HSV color is within the specified range for orange
    cv::inRange(hsv_color, whiteLower, whiteUpper, mask);

    // Check if any pixel is in the range (i.e., if any pixel in the mask is non-zero)
    return cv::countNonZero(mask) > 0;
}

Mat detect_color(Mat img, double x, double y, double r){
    cv::Point center(x, y); // create point object for circle center
    // Draw the circumference of the circle
    cv::circle(img, center, r, cv::Scalar(0, 255, 0), 2);
    // Draw a small circle (of radius 1) to show the center
    cv::circle(img, center, 1, cv::Scalar(0, 0, 255), 3);
    //imshow("Image with Circle",img);

    // Detecting Color
    // Create a mask for the circle
    cv::Mat mask(img.size(), CV_8U, cv::Scalar(0));
    cv::circle(mask, center, r, cv::Scalar(255), -1);  // Filled circle
    //imshow("Mask",mask);

    // Calculate the mean color inside the circle using the mask
    cv::Scalar meanColor = cv::mean(img, mask);

    // CONVERT TO HSV
    cv::Mat meanColorBGR(1, 1, CV_8UC3, meanColor);
    cv::Mat meanColorHSV;
    cv::cvtColor(meanColorBGR, meanColorHSV, cv::COLOR_BGR2HSV);

    if(isColorOrange(meanColorHSV)) {
        //std::cout<< "TRUE";
    };

    return meanColorHSV;

}

// TODO -> return the coords and center from this function
void edge_detection(Mat img){
    //imshow("origninal image",img);

    // Convert to grayscale
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // Blur using a kernel specified by the size of blur_matrix variable below
    cv::Mat grayBlurred;
    int blur_matrix = 7;
    cv::blur(gray, grayBlurred, cv::Size(blur_matrix, blur_matrix));

    // Apply Hough transform on the blurred image
    int maxBallRadius = 100;
    int minDist = grayBlurred.rows / 8;
    std::vector<cv::Vec3f> detectedCircles; // store the detected circles here
    cv::HoughCircles(grayBlurred, detectedCircles, cv::HOUGH_GRADIENT, 1,
                     minDist,  // change this value to detect circles with different distances to each other
                     50, 30, 1, maxBallRadius);

    // Draw circles that are detected
    for (size_t i = 0; i < detectedCircles.size(); i++){
        std::cout << "\n  - Circle: " << (i+1) << "." ;

        // Get the center and radius of the circle
        cv::Point center(cvRound(detectedCircles[i][0]), cvRound(detectedCircles[i][1])); // firse two vals in circle vector is corrds
        int radius = cvRound(detectedCircles[i][2]); // third value is radius

        // Draw the circumference of the circle on the original image
        cv::circle(img, center, radius, cv::Scalar(0, 255, 0), 2);

        // Draw a small dot to show the center on the original image
        cv::circle(img, center, 1, cv::Scalar(0, 0, 255), 3);
        std::cout << "\n      -> Center : (" << center.x << ", " << center.y << ")" ;

        // Get the average color of the Ball ie the area of the circle.
        cv::Mat hsvBallColor = detect_color(img,center.x,center.y,radius);

        // Check to see if the detected circles are orange or white
        bool orange = isColorOrange(hsvBallColor);
        if(orange){
            std::cout << "\n      -> Ball is Orange" << (i + 1); }
        bool white = isColorWhite(hsvBallColor);
        if(white){
            std::cout << "\n      -> Ball is White" << (i + 1); }


    }
    cv::imshow("Detected Circles", img);

}



//This function returns the mean color of the circle in the image supplied
void find_center(int image_no){
    string path = "/Users/cianmurphy/code_directories/vision_ass_1/balls/Ball" + to_string(image_no) + ".jpg";  // TODO add a constant for the start of the path
    Mat ball_img = imread(path); // read in ball image from the path
    //imshow("Ball " + to_string(image_no)+"  Image" ,ball_img);  // display original image
    edge_detection(ball_img);

}

void iterate_through_ball_images(){
    for (int i = 1; i < 10; ++i) {
        std::cout << "\n\nImage " << i << "";
        find_center(i);
    }
}

//void ball_detection_test(){
//    string path = "/Users/cianmurphy/code_directories/vision_ass_1/balls/Ball8.jpg";
//    Mat img = imread(path);
//    detect_color(img,523.5,	458.5	,61/2);
//
//}

void part_1(){
    iterate_through_ball_images();
    //find_center(9);
    //ball_detection_test();

}