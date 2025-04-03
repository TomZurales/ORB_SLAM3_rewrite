set(SOURCES 
    src/system.cc    
    src/map.cc
    src/base.cc
    src/utility.cc
    src/frame.cc
    src/camera.cc
)

find_package(Sophus REQUIRED)
find_package(OpenCV REQUIRED)

set(SLAM_LIBRARY_NAME orb_slam3_rewrite)
add_library(${SLAM_LIBRARY_NAME} SHARED ${SOURCES})
target_include_directories(${SLAM_LIBRARY_NAME} PUBLIC include)
target_include_directories(${SLAM_LIBRARY_NAME} PUBLIC include/external)
target_link_libraries(${SLAM_LIBRARY_NAME} Sophus::Sophus ${OpenCV_LIBS})

add_executable(testFrame test/testFrame.cc)
target_link_libraries(testFrame ${SLAM_LIBRARY_NAME})