set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories to bin/[config] 
# You can set CMAKE_BINARY_DIR to compile into out/bin/...

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>)

# Function to copy dependencies after build (similar to dotnet)
# function(copy_dependencies_after_build target dependencies_dir)
#   add_custom_command(TARGET ${target} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E make_directory 
#     "$<TARGET_FILE_DIR:${target}>"
#     COMMENT "Creating target directory")
    
#   foreach(dependency_file ${ARGN})
#     add_custom_command(TARGET ${target} POST_BUILD
#       COMMAND ${CMAKE_COMMAND} -E copy_if_different
#       "${dependencies_dir}/${dependency_file}"
#       "$<TARGET_FILE_DIR:${target}>/"
#       COMMENT "Copying ${dependency_file} to output directory")
#   endforeach()
# endfunction()

include(cmake/CompilerOptions.cmake)
