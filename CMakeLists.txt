cmake_minimum_required(VERSION 3.28)

project(orb_slam3_rewrite)

# Get all environment variables in .env
if(EXISTS "${CMAKE_SOURCE_DIR}/.env")
    file(READ "${CMAKE_SOURCE_DIR}/.env" ENV_CONTENTS)
    string(REPLACE "\n" ";" ENV_LINES "${ENV_CONTENTS}")
    foreach(ENV_LINE IN LISTS ENV_LINES)
        if(ENV_LINE MATCHES "^[^#]+=")
            string(REGEX REPLACE "([^=]+)=(.*)" "\\1" ENV_VAR_NAME "${ENV_LINE}")
            string(REGEX REPLACE "([^=]+)=(.*)" "\\2" ENV_VAR_VALUE "${ENV_LINE}")
            set(${ENV_VAR_NAME} "${ENV_VAR_VALUE}")
        endif()
    endforeach()
endif()

add_subdirectory(orb_slam3_rewrite)

# add_subdirectory(implementation/stereo_inertial_oak_d)