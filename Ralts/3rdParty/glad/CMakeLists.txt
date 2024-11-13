cmake_minimum_required(VERSION 3.20)
project(glad)

set(LIBRARY_OUTPUT_PATH ${LIBPATH})
add_library(glad STATIC src/glad.c)