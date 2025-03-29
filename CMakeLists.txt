cmake_minimum_required(VERSION 3.28)

project(orb_slam3_rewrite)

set(SOURCES 
    src/map.cc
)

set(SLAM_LIBRARY_NAME orb_slam3_rewrite)
add_library(${SLAM_LIBRARY_NAME} SHARED ${SOURCES})
target_include_directories(${SLAM_LIBRARY_NAME} PRIVATE include)