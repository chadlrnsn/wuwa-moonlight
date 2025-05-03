cmake_minimum_required(VERSION 3.15...4.0)
project(SDK)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES_SDK 
    SDK/Basic.cpp
    SDK/Engine_functions.cpp
    SDK/CoreUObject_functions.cpp
    SDK/KuroUtility_functions.cpp
)

add_library(SDK STATIC ${SOURCES_SDK})

target_include_directories(SDK PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/SDK/
    ${CMAKE_CURRENT_SOURCE_DIR}/
)