cmake_minimum_required(VERSION 3.20)
project(Ralts)
set(CMAKE_CXX_STANDARD 17)  

set(EXECUTABLE_OUTPUT_PATH ${OUTPATH})

file(GLOB SRC "*.cpp" ${3RDPATH}/stb_image/*.cpp)

link_directories(${LIBPATH})
add_executable(Ralts ${SRC})
target_link_libraries(Ralts PUBLIC glfw3 app glad)

target_precompile_headers(Ralts PUBLIC pch.h)

