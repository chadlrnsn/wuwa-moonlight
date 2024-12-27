cmake_minimum_required(VERSION 3.15)
project(wuwa-moonlight) # DO NOT CHANGE THIS LINE

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable parallel compilation for MSVC
if(MSVC)
    add_compile_options(/MP)
    # Optimize linking
    add_link_options(/DEBUG:FASTLINK)
endif()

# Group source files by directories in IDE
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CPP_SOURCES})

# More efficient way to collect sources
file(GLOB_RECURSE CPP_SOURCES 
    "${PROJECT_NAME}/src/*.cpp"
    "${PROJECT_NAME}/utils/*.cpp"
)

file(GLOB IMGUI_SOURCES
    ${PROJECT_NAME}/vendor/imgui/*.cpp
    ${PROJECT_NAME}/vendor/imgui/backends/imgui_impl_dx11.cpp
    ${PROJECT_NAME}/vendor/imgui/backends/imgui_impl_win32.cpp
)

add_subdirectory(${PROJECT_NAME}/vendor/CppSDK)
add_subdirectory(${PROJECT_NAME}/vendor/minhook)

add_library(${PROJECT_NAME} SHARED
    ${CPP_SOURCES}
    ${IMGUI_SOURCES}
    ${PROJECT_NAME}/vendor/kiero/kiero.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDK
    minhook 
    Shell32
)

# Use generator expressions for paths
target_include_directories(${PROJECT_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/src>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/CppSDK>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/CppSDK/SDK>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/kiero>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/minhook>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/minhook/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/logger>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/fonts>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/imgui>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/imgui/backends>
)

# Disable warnings for third-party libraries
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra>
)