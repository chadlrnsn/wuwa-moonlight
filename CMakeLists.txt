cmake_minimum_required(VERSION 3.15)
project(wuwa-moonlight)

file(GLOB_RECURSE CPP_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/src/*.cpp
)

add_subdirectory(${PROJECT_NAME}/vendor/CppSDK)

add_library(${PROJECT_NAME} SHARED
    ${CPP_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDK
    minhook 
    Shell32
)



target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/CppSDK
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/CppSDK/SDK
) 