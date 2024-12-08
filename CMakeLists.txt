cmake_minimum_required(VERSION 3.5.0...${CMAKE_VERSION})
project(DoIP_platform VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 20)

if (UNIX AND NOT APPLE)
    set (LINUX true)
endif()

set(sockpp_DIR lib/sockpp)
set(doip_lib_DIR lib/DoIP-Lib)
set(spdlog_DIR lib/spdlog)

# set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build all libraies as static")

option(build_tests "Build all the test of DoIP-Lib" OFF)

add_subdirectory(${doip_lib_DIR})
add_subdirectory(${sockpp_DIR})
add_subdirectory(${spdlog_DIR})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE doip_lib
    PRIVATE sockpp
    PRIVATE spdlog
)

if (0)

target_include_directories(${PROJECT_NAME}

)
endif()
