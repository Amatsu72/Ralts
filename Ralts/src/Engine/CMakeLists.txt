cmake_minimum_required(VERSION 3.20)
project(engine)
set(CMAKE_CXX_STANDARD 17)  

set(LIBRARY_OUTPUT_PATH ${LIBPATH})

file(GLOB ENGINESRC 
    "./Component/*.cpp"
    "./Core/*.cpp" 
    "./Event/*.cpp" 
    "./System/*.cpp"
)
add_library(engine STATIC ${ENGINESRC})
target_link_libraries(engine PUBLIC glfw glad)

