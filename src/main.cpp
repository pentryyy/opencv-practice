#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

int main() {
    string image_path = "images/image.jpg";
    
    if (!fs::exists(image_path)) {
        cout << "Ошибка: файл " << image_path << " не найден!" << endl;
        return -1;
    }
    
    Mat image = imread(image_path);
    
    if (image.empty()) {
        cout << "Ошибка: не удалось загрузить изображение из " << image_path << endl;
        return -1;
    }
    
    int height = image.rows;
    int width  = image.cols;
    
    Point center_coordinates(
        width / 2, 
        height / 2 - 140
    );

    Scalar circle_color(0, 255, 0);

    int radius    = 100;
    int thickness = 3;
    
    circle(
        image, 
        center_coordinates, 
        radius, 
        circle_color, 
        thickness
    );
    
    string text           = "Hello OpenCV!";
    int    font           = FONT_HERSHEY_SIMPLEX;
    double font_scale     = 1.0;
    int    text_thickness = 2;
 
    Scalar text_color(160, 160, 160);

    Size text_size = getTextSize(
        text, 
        font, 
        font_scale, 
        text_thickness, 
        0
    );
    
    int text_x = (width - text_size.width) / 2;
    int text_y = height / 2 + radius + 50;
    
    putText(
        image, 
        text, 
        Point(text_x, text_y), 
        font, 
        font_scale, 
        text_color, 
        text_thickness
    );
    
    imshow("OpenCV Image Showing", image);
    waitKey(0);
    destroyAllWindows();
    
    return 0;
}
