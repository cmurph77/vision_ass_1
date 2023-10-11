void find_center(int image_no){
    //cout<<"Finding the location of the ball in image" << image_no;
    string path = "/Users/cianmurphy/vision_ass_1/balls/Ball" + to_string(image_no) + ".jpg";  // TODO add a constant for the start of the path
    Mat ball_img = imread(path); // read in ball image from the path
    imshow("Ball " + to_string(image_no)+"  Image" ,ball_img);  // display original image

    /// ******* ENTER THE FUNCTION YOU WANT TO USE TO FIND BALL CENTER ***************
    clustering_attempt(ball_img);
}


void iterate_through_ball_images(){
    for (int i = 1; i < 5; ++i) {
        std::cout << "Image " << i << " ->";
        find_center(i);
    }
}

void part_1(){
    std::cout << "Starting Part 1.";

}