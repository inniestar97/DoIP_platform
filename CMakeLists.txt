cmake_minimum_required(VERSION 3.5.0)
project(DoIP_platform VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 14)

if (UNIX AND NOT APPLE)
    set (LINUX true)
endif()

set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")

add_executable(${PROJECT_NAME} main.cpp)

set(DoIP-Lib_DIR "${LIB_DIR}/DoIP-Lib")
set(sockpp_DIR "${LIB_DIR}/sockpp")

target_include_directories(${PROJECT_NAME} PUBLIC
    ${DoIP-Lib_DIR}/include
    ${sockpp_DIR}/include
)

if (LINUX)

    target_link_libraries(${PROJECT_NAME} PUBLIC
        ${DoIP-Lib_DIR}/build/libdoip_lib.a
        ${sockpp_DIR}/build/libsockpp.so
    )

elseif (APPLE)

    target_link_libraries(${PROJECT_NAME} PUBLIC
        ${DoIP-Lib_DIR}/build/libdoip_lib.a
        ${sockpp_DIR}/build/libsockpp.dylib
    )

endif()
