set(SOURCES 
    src/stereo_inertial_oak_d.cc
    src/oak_d.cc
)

find_package(depthai REQUIRED)

add_executable(stereo_inertial_oak_d ${SOURCES})
target_include_directories(stereo_inertial_oak_d PRIVATE include)
target_link_libraries(stereo_inertial_oak_d orb_slam3_rewrite depthai::opencv)