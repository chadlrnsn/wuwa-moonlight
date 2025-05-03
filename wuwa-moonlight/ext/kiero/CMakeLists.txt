cmake_minimum_required(VERSION 3.5...4.0)
project(kiero)

set(CMAKE_CXX_STANDARD 17)

file(GLOB KIERO_SOURCES "kiero.cpp")

add_library(kiero STATIC ${KIERO_SOURCES})

target_include_directories(kiero PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/ext/minhook
)

target_link_libraries(kiero PUBLIC minhook)
