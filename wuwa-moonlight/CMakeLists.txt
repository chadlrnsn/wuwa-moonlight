cmake_minimum_required(VERSION 3.5...4.0)
project(WWMoonlight)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_library(WWMoonlight SHARED ${SOURCES})

target_include_directories(WWMoonlight PUBLIC 
    src
    src/utils
    src/Hooks

    # External dependencies
    ext/minhook
    ext/minhook/include
    ext/CppSDK
    ext/CppSDK
    ext/imgui
    ext/imgui/backends
    ext/kiero
    ext/json/include
    ext/magic_enum/include/magic_enum
    ext/xorstr/include
)

file(GLOB IMGUI_SOURCES 
    ext/imgui/*.cpp
    ext/imgui/backends/imgui_impl_win32.cpp 
    ext/imgui/backends/imgui_impl_dx11.cpp
)

add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC 
    ext/imgui
    ext/imgui/backends
)

add_subdirectory(ext/minhook)
add_subdirectory(ext/CppSDK)
add_subdirectory(ext/kiero)
add_subdirectory(ext/json)

target_link_libraries(WWMoonlight PUBLIC d3d11 dxgi minhook SDK imgui kiero)

target_compile_definitions(WWMoonlight PUBLIC _CRT_SECURE_NO_WARNINGS)

