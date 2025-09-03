import cv2
import os

def main():
    image_path = 'images/image.jpg'
    
    if not os.path.exists(image_path):
        print(f"Ошибка: файл {image_path} не найден!")
        exit()
    
    image = cv2.imread(image_path)

    if image is None:
        print(f"Ошибка: не удалось загрузить изображение из {image_path}")
        exit()
    
    height, width = image.shape[:2]
    
    center_coordinates = (
        width // 2, 
        height // 2 - 140
    )
    radius = 100
    circle_color = (0, 255, 0)
    thickness = 3
    
    cv2.circle(image, center_coordinates, radius, circle_color, thickness)
    
    text = "Hello OpenCV!"
    font = cv2.FONT_HERSHEY_SIMPLEX
    font_scale = 1
    text_color = (160, 160, 160)
    text_thickness = 2
    
    text_size = cv2.getTextSize(text, font, font_scale, text_thickness)[0]
    text_x = (width - text_size[0]) // 2
    text_y = height // 2 + radius + 50
    
    cv2.putText(
        image, 
        text, 
        (text_x, text_y), 
        font, 
        font_scale, 
        text_color, 
        text_thickness
    )
    
    cv2.imshow("OpenCV Image Showing", image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()