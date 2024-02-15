#minimum required cmake version
cmake_minimum_required(VERSION 3.8)

#project name
project(Simulator)

#Adding the static library path previously created
add_subdirectory("Ray_Tracing")

#define source files
set(SOURCES
    src/main.cpp
    )

#Adding executing file
add_executable(Simulator ${SOURCES})

#link static libs
target_link_libraries(Simulator rayLib)



