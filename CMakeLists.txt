cmake_minimum_required(VERSION 3.20)
project(Ralts)
set(CMAKE_CXX_STANDARD 17)  

set(OUTPATH ${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE})
set(LIBPATH ${PROJECT_SOURCE_DIR}/Ralts/lib)
# if(WIN32)
#     message(STATUS "Configuring for Windows!")
# elseif(APPLE)
#     message(STATUS "Configuring for macOS!")
# endif()

include_directories(Ralts/3rdParty)

add_subdirectory(Ralts/src Ralts/src/App)

