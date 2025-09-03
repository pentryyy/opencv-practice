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
    
    cv2.imshow('Image', image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()