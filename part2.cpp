void test(){

    Mat table_img = imread("/Users/cianmurphy/code_directories/vision_ass_1/tables/Table4.jpg");
    cv::Mat image = cv::Mat::zeros(300, 300, CV_8UC3);

    int tr_x = 1347;
    int tr_y = 766;

    int tl_x = 2640;
    int tl_y = 828;

    int br_x = 350;
    int br_y = 3000;

    int bl_x = 3958;
    int bl_y = 2963;

    int x = 3958;
    int y = 2963;

    cv::circle(table_img, cv::Point(tr_x, tr_y), 10, cv::Scalar(0, 0, 255), -1); // -1 for a filled circle
    cv::circle(table_img, cv::Point(tl_x,tl_y), 10, cv::Scalar(0, 0, 255), -1); // -1 for a filled circle
    cv::circle(table_img, cv::Point(br_x,br_y), 10, cv::Scalar(0, 0, 255), -1); // -1 for a filled circle
    cv::circle(table_img, cv::Point(bl_x, bl_y), 10, cv::Scalar(0, 0, 255), -1); // -1 for a filled circle

    imshow("Table 4",table_img);

}

// Draws 4 points on an image
void drawPoints(vector<Point2f> points, Mat img){
    for (size_t i = 0; i < points.size(); i++){
        std::cout << "\n  - Circle: " << (i+1) << "." ;

        //cv::Point center(cvRound(points[i]), cvRound(points[i][1])); // firse two vals in circle vector is corrds

        // Draw a small circle (of radius 1) to show the center
        cv::circle(img, points[i], 10, cv::Scalar(0, 255, 0), -1);
    }
    imshow("image",img);
}

// TODO - CORNER DETECTION NEEDS TO BE WRITTEN
vector<Point2f> detectCorners(Mat img){
    vector<Point2f> points;

    //Artificially Add points for the momment
    //1342	768	2645	833	345	3004	3963	2966
    points.push_back(cv::Point(1342, 768));  // Point 1
    points.push_back(cv::Point(2645, 833));  // Point 2
    points.push_back(cv::Point(345, 3004));  // Point 3
    points.push_back(cv::Point(3963, 2966));  // Point 4

    return points;
}


Mat perform_blue_mask(Mat img){
    // Define the green color range
    cv::Scalar blueLower(100, 40, 30);
    cv::Scalar blueUpper(130,255,255);

    // Apply Gaussian blur
    //cv::GaussianBlur(img, img, cv::Size(11, 11), 0);

    // Convert to HSV color space
    cv::Mat hsv;
    cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);

    // Create a mask for the orange color
    cv::Mat mask;
    cv::inRange(hsv, blueLower, blueUpper, mask);

    // Perform dilations and erosions on the mask
    cv::erode(mask, mask, cv::Mat(), cv::Point(-1, -1), 2);
    cv::dilate(mask, mask, cv::Mat(), cv::Point(-1, -1), 2);

    Mat blue_masked_image;
    cv::bitwise_and(img, img, blue_masked_image, mask=mask);

    return blue_masked_image;
//    return mask;

}

Mat draw_mask_edges(cv::Mat& originalImage, const cv::Mat& mask) {
    // Convert the mask to grayscale
    cv::Mat maskGray;
    cv::cvtColor(mask, maskGray, cv::COLOR_BGR2GRAY);

    // Find edges in the mask using Canny edge detection
    cv::Mat edges;
    cv::Canny(maskGray, edges, 50, 150, 3);
    imshow("edges from function",edges);

    // Create a mask for the edges
    cv::Mat edgeMask = cv::Mat::zeros(originalImage.size(), CV_8UC1);
    edges.copyTo(edgeMask, edges);

    // Convert the edge mask to 3 channels (BGR)
    cv::Mat edgeMaskBGR;
    cv::cvtColor(edgeMask, edgeMaskBGR, cv::COLOR_GRAY2BGR);

    // Overlay the edges on the original image
    cv::Mat result;
    cv::addWeighted(originalImage, 0.7, edgeMaskBGR, 0.3, 0, result);

    //originalImage = result;
    return result;
}

void hsv_approach(Mat img){
    Mat mask = perform_blue_mask(img); // TODO - FIND THE SMALLEST BOUNDING RECTANGlE
    //imshow("Masked Image", mask);

//    Mat edge = draw_mask_edges(img,mask);
//    imshow("edges", edge);
    drawPoints(detectCorners(mask),mask);



}

void findingTableCorners(){
    Mat table_img = imread("/Users/cianmurphy/code_directories/vision_ass_1/tables/Table4.jpg");
    cv::Mat image = cv::Mat::zeros(300, 300, CV_8UC3);

    int tr_x = 1347;
    int tr_y = 766;

    int tl_x = 2640;
    int tl_y = 828;

    int br_x = 350;
    int br_y = 3000;

    int bl_x = 3958;
    int bl_y = 2963;

    int x = 3958;
    int y = 2963;

    cv::circle(table_img, cv::Point(tr_x, tr_y), 10, cv::Scalar(0, 0, 255), -1); // -1 for a filled circle
    cv::circle(table_img, cv::Point(tl_x,tl_y), 10, cv::Scalar(0, 0, 255), -1); // -1 for a filled circle
    cv::circle(table_img, cv::Point(br_x,br_y), 10, cv::Scalar(0, 0, 255), -1); // -1 for a filled circle
    cv::circle(table_img, cv::Point(bl_x, bl_y), 10, cv::Scalar(0, 0, 255), -1); // -1 for a filled circle

    imshow("Table 4",table_img);
}

Mat perspectiveTransform(const std::vector<cv::Point2f>& points, cv::Mat img) {
    int height = 900;
    int width = 500;
    if (points.size() < 4) {
        std::cerr << "Insufficient points for perspective transformation." << std::endl;
        return img;
    }

    cv::Point2f pts1[] = {
            points[0],  // top-right
            points[1],  // top-left
            points[2],  // bottom-right
            points[3]   // bottom-left
    };

    cv::Point2f pts2[] = {
            cv::Point2f(0, 0),
            cv::Point2f(width, 0),
            cv::Point2f(0, height),
            cv::Point2f(width, height)
    };

    cv::Mat matrix = cv::getPerspectiveTransform(pts1, pts2);
    cv::Mat result;
    cv::warpPerspective(img, result, matrix, cv::Size(width, height));

    cv::imshow("Image", img);
    cv::imshow("Perspective transformation", result);
    return result;
}

void testCornerDetection(int img_no){
    // load in image
    string path = "/Users/cianmurphy/code_directories/vision_ass_1/tables/Table" + to_string(img_no) + ".jpg";  //
    Mat original_img = imread(path);
    //imshow("og",original_img);

    // perform corner detection
    std::vector<cv::Point2f> points = detectCorners(original_img);

    std::cout << "\n\nThe co-ords for the corners on Image: " <<img_no<<" ";

    int x; int y;
    for(int i = 0; i < 4;i++){
        std::cout << "\n  -> " << points[i];

    }
}

void iterate_corner_test(){
    for(int i=0; i <5; i++){
        testCornerDetection(i+1);
    }
}

void part2(){
    Mat img = imread("/Users/cianmurphy/code_directories/vision_ass_1/tables/Table4.jpg");
    hsv_approach(img);
//    vector<Point2f> points = detectCorners(img);
//    drawPoints(points,img);
//    imshow("Warped Perspective Image",perspectiveTransform(points, img));
//    testCornerDetection(1);
//    iterate_corner_test();

}