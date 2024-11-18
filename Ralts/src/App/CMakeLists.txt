cmake_minimum_required(VERSION 3.20)
project(app)
set(CMAKE_CXX_STANDARD 17)  

set(LIBRARY_OUTPUT_PATH ${LIBPATH})

file(GLOB APPSRC "*.cpp")
add_library(app STATIC ${APPSRC})
target_link_libraries(app PUBLIC engine)

