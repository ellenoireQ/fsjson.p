cmake_minimum_required(VERSION 3.18)
project(fsjson VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

execute_process(
    COMMAND git describe --dirty --always
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE APP_COMMIT
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
)

if(NOT APP_COMMIT)
    set(APP_COMMIT "unknown")
endif()

set(SOURCES
    main.cpp
)

set(HEADERS
    version.h
    regex/helper.h
    regex/read_cli.h
    regex/filesystem.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Compile definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE
    APP_COMMIT="${APP_COMMIT}"
)

# Android settings
if(ANDROID)
    # Android NDK toolchain settings
    set(CMAKE_ANDROID_STL_TYPE c++_shared)
    
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -fPIC
    )
else()
    # Desktop
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
    )
endif()

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/regex
)
