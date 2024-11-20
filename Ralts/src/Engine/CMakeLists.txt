cmake_minimum_required(VERSION 3.20)
project(engine)
set(CMAKE_CXX_STANDARD 17)  

set(LIBRARY_OUTPUT_PATH ${LIBPATH})

file(GLOB ENGINESRC 
    "./ECS/Base/*.cpp"
    "./ECS/Component/*.cpp"
    "./ECS/System/*.cpp"
    "./Core/*.cpp" 
    "./Event/*.cpp" 

)
add_library(engine STATIC ${ENGINESRC})
target_link_libraries(engine PUBLIC glfw glad app)

