cmake_minimum_required(VERSION 3.15)
project(wuwa-moonlight) # DO NOT CHANGE THIS LINE

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE CPP_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/src/*.cpp
)

set(IMGUI_SOURCES
    ${PROJECT_NAME}/vendor/imgui/imgui.cpp
    ${PROJECT_NAME}/vendor/imgui/imgui_demo.cpp
    ${PROJECT_NAME}/vendor/imgui/imgui_draw.cpp
    ${PROJECT_NAME}/vendor/imgui/imgui_tables.cpp
    ${PROJECT_NAME}/vendor/imgui/imgui_widgets.cpp
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

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/CppSDK
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/CppSDK/SDK
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/kiero
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/minhook
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/minhook/include
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/logger
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/fonts
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/vendor/imgui/backends
) 