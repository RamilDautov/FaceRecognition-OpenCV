cmake_minimum_required(VERSION 3.16)

project(FaceRecognition)

set(CMAKE_CXX_STANDARD 17)
set(OpenCV_DIR ${OPEN_CV_LIB_PATH})


set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)

find_package( OpenCV REQUIRED )

MESSAGE(STATUS "Include dirs ${OpenCV_INCLUDE_DIRS}")
MESSAGE(STATUS "LINK LIBRARIES ${OpenCV_LIBS}")

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(FaceRecognition main.cpp)

target_link_libraries( FaceRecognition ${OpenCV_LIBS} )

add_custom_command(TARGET FaceRecognition POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${RESOURCES_DIR}/haarcascade_frontalface_alt.xml"
        "${RESOURCES_DIR}/opencv_world455.dll"
        $<TARGET_FILE_DIR:FaceRecognition>)
