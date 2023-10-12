void part2(){

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