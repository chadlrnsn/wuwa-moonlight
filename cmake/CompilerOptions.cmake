# Set compiler options for different compilers and build types

# Common options for all compilers
set(COMMON_CXX_FLAGS "")
set(COMMON_CXX_FLAGS_DEBUG "")
set(COMMON_CXX_FLAGS_RELEASE "")

# Clang specific options
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # Debug options
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -Wpedantic -Werror")
    
    # Release options
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG -Wall -Wextra")
    
    # Enable address sanitizer in debug mode
    option(ENABLE_ASAN "Enable Address Sanitizer" OFF)
    if(ENABLE_ASAN AND CMAKE_BUILD_TYPE MATCHES Debug)
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")
    endif()
endif()

# MSVC specific options
if(MSVC)
    # Debug options
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zi /Od /W4")
    
    # Release options
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /DNDEBUG /W4")
    
    # Disable specific warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /EHsc /bigobj /wd4309 /wd4369 /wd4324 /wd4458 /wd4459 /wd4100 /wd4189 /wd4102 /wd4244 /wd4456 /wd4701 /wd4703 /wd4063 /wd4477")
    
    # Use static runtime
    option(MSVC_STATIC_RUNTIME "Use static runtime" OFF)
    if(MSVC_STATIC_RUNTIME)
        foreach(flag_var
            CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
            if(${flag_var} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
            endif()
        endforeach()
    endif()
endif()

# Print compiler flags
message(STATUS "C++ flags (Debug): ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "C++ flags (Release): ${CMAKE_CXX_FLAGS_RELEASE}")
