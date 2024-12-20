cmake_minimum_required(VERSION 3.15)
project(cheat-library)

file(GLOB_RECURSE CPP_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/wuwa-moonlight/*.cpp
)

add_subdirectory(SDK)

add_library(${PROJECT_NAME} SHARED
    ${CPP_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDK)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/wuwa-moonlight
    ${CMAKE_CURRENT_SOURCE_DIR}/wuwa-moonlight/vendor
    ${CMAKE_CURRENT_SOURCE_DIR}/wuwa-moonlight/vendor/kiero
    ${CMAKE_CURRENT_SOURCE_DIR}/wuwa-moonlight/vendor/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/wuwa-moonlight/vendor/imgui/backends
    ${CMAKE_CURRENT_SOURCE_DIR}/wuwa-moonlight/src
    ${CMAKE_CURRENT_SOURCE_DIR}/wuwa-moonlight/src/framework
) 