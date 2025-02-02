project(Injector)

file(GLOB_RECURSE SOURCES "*.cpp")

add_executable(Injector ${SOURCES})

target_include_directories(Injector PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/injector
    # ... existing includes ...
)