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

// draws 4 points on an image
void drawPoints(std::vector<cv::Point> points, Mat img){
    for (size_t i = 0; i < points.size(); i++){
        std::cout << "\n  - Circle: " << (i+1) << "." ;

        //cv::Point center(cvRound(points[i]), cvRound(points[i][1])); // firse two vals in circle vector is corrds

        // Draw a small circle (of radius 1) to show the center
        cv::circle(img, points[i], 10, cv::Scalar(0, 255, 0), -1);
    }
    imshow("image",img);
}

std::vector<cv::Point> detectCorners(Mat img){
    std::vector<cv::Point> points;

    //Artificially Add points for the momment
    //1342	768	2645	833	345	3004	3963	2966
    points.push_back(cv::Point(1342, 768));  // Point 1
    points.push_back(cv::Point(2645, 833));  // Point 2
    points.push_back(cv::Point(345, 3004));  // Point 3
    points.push_back(cv::Point(3963, 2966));  // Point 4

    return points;
}

void part2(){
    Mat img = imread("/Users/cianmurphy/code_directories/vision_ass_1/tables/Table4.jpg");
    std::vector<cv::Point> points = detectCorners(img);
    drawPoints(points,img);
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