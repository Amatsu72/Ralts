cmake_minimum_required(VERSION 3.10)

project(Ralts)

set(CMAKE_CXX_STANDARD 17)  

# include_directories(include)

add_executable(Ralts main.cpp)

if(WIN32)
    message(STATUS "Configuring for Windows")
elseif(APPLE)
    message(STATUS "Configuring for macOS")
endif()