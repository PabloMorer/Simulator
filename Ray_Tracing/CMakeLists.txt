#cmake minimum required version
cmake_minimum_required (VERSION 3.8)

#project name
project ("Ray_Tracing")

set(SOURCES
    src/main.cpp
    )

## static library

add_library(rayLib STATIC ${SOURCES})

#Including src folder to look for head files
target_include_directories(rayLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
