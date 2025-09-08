#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

#define fs std::filesystem

int main() {
    std::string image_path = "images/image.jpg";
    
    if (!fs::exists(image_path)) {
        std::cout
            << "Ошибка: файл " 
            << image_path 
            << " не найден!" 
            << std::endl;
        
        return -1;
    }
    
    cv::Mat image = cv::imread(image_path);
    
    if (image.empty()) {
        std::cout 
            << "Ошибка: не удалось загрузить изображение из " 
            << image_path 
            << std::endl;
        
        return -1;
    }
    
    int height = image.rows;
    int width  = image.cols;
    
    cv::Point center_coordinates(
        width / 2, 
        height / 2 - 140
    );

    cv::Scalar circle_color(0, 255, 0);

    int radius    = 100;
    int thickness = 3;
    
    cv::circle(
        image, 
        center_coordinates, 
        radius, 
        circle_color, 
        thickness
    );
    
    std::string text           = "Hello OpenCV!";
    int         font           = cv::FONT_HERSHEY_SIMPLEX;
    double      font_scale     = 1.0;
    int         text_thickness = 2;
 
    cv::Scalar text_color(160, 160, 160);

    cv::Size text_size = cv::getTextSize(
        text, 
        font, 
        font_scale, 
        text_thickness, 
        0
    );
    
    int text_x = (width - text_size.width) / 2;
    int text_y = height / 2 + radius + 50;
    
    cv::putText(
        image, 
        text, 
        cv::Point(text_x, text_y), 
        font, 
        font_scale, 
        text_color, 
        text_thickness
    );
    
    cv::imshow("OpenCV Image Showing", image);
    cv::waitKey(0);
    cv::destroyAllWindows();
    
    return 0;
}
