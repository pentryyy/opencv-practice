cmake_minimum_required(VERSION 3.12)
project(OpenCVProject)

set(CMAKE_CXX_STANDARD 11)

set(OpenCV_DIR "C:/opencv/build")
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "C:/opencv/build/x64/vc16/bin/opencv_world4120.dll"
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})