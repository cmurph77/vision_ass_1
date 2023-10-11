void clustering_attempt(Mat image){
    // Reshape the image to a 2D matrix of pixels (rows = height * width, cols = 3 for BGR)
    cv::Mat reshaped_image = image.reshape(1, image.rows * image.cols);

    // Convert to 32-bit floating-point and normalize to the range [0, 1]
    reshaped_image.convertTo(reshaped_image, CV_32F, 1.0 / 255.0);

    // Define the number of clusters (K)
    int K = 8;

    // K-means clustering
    cv::Mat labels, centers;
    //cv::kmeans(reshaped_image, K, labels, cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, 100, 0.2), 3, cv::KMEANS_RANDOM_CENTERS, centers);

    // Convert the centers to 8-bit integers
    //centers.convertTo(centers, CV_8U);

    // Reshape the labels back to the original image size
    //cv::Mat segmented_image = labels.reshape(1, image.rows);

    // Display the original image and the segmented image
    cv::imshow("Original Image", image);
    //cv::imshow("Segmented Image", segmented_image);
}

