set(SOURCES 
    src/map.cc
)

find_package(Sophus REQUIRED)
find_package(OpenCV REQUIRED)

set(SLAM_LIBRARY_NAME orb_slam3_rewrite)
add_library(${SLAM_LIBRARY_NAME} SHARED ${SOURCES})
target_include_directories(${SLAM_LIBRARY_NAME} PRIVATE include)
target_include_directories(${SLAM_LIBRARY_NAME} PUBLIC include/external)
target_link_libraries(${SLAM_LIBRARY_NAME} Sophus::Sophus ${OpenCV_LIBS})