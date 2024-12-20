cmake_minimum_required(VERSION 3.15)
project(SDK)

set(SOURCES_SDK 
    # SDK/AudioExtensions_functions.cpp
    SDK/Basic.cpp
    SDK/Engine_functions.cpp
    SDK/CoreUObject_functions.cpp
)

add_library(SDK STATIC ${SOURCES_SDK})

target_include_directories(SDK PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/SDK/
    ${CMAKE_CURRENT_SOURCE_DIR}/
)

