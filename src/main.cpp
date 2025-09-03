#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    Mat image(500, 500, CV_8UC3, Scalar(0, 0, 0));
    
    circle(
        image, 
        Point(250, 250), 
        100, 
        Scalar(0, 0, 255), 
        3
    );
    
    putText(
        image, 
        "Hello OpenCV!", 
        Point(150, 100), 
        FONT_HERSHEY_SIMPLEX, 
        1, 
        Scalar(255, 255, 255), 
        2
    );
    
    imshow("OpenCV Example", image);
    
    waitKey(0);
    
    return 0;
}