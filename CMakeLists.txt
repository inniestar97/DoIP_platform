cmake_minimum_required(VERSION 3.5.0)
project(DoIP_platform VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 17)

if (UNIX AND NOT APPLE)
    set (LINUX true)
endif()

set(sockpp_DIR lib/sockpp)
set(doip_lib_DIR lib/DoIP-Lib)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build all libraies as static")

add_subdirectory(${doip_lib_DIR})
add_subdirectory(${sockpp_DIR})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE doip_lib
    PRIVATE sockpp
)

if (0)
target_include_directories(${PROJECT_NAME}

)
endif()