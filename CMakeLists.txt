cmake_minimum_required(VERSION 3.20)

project(Ralts)

set(CMAKE_CXX_STANDARD 17)  

# include_directories(include)
set(SRC_LIST Ralts/src/main.cpp)
add_executable(Ralts ${SRC_LIST})

if(WIN32)
    message(STATUS "Configuring for Windows!")
elseif(APPLE)
    message(STATUS "Configuring for macOS!")
endif()