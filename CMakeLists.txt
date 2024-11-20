cmake_minimum_required(VERSION 3.20)
project(Ralts)
set(CMAKE_CXX_STANDARD 17)  

set(OUTPATH ${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE})
set(LIBPATH ${PROJECT_SOURCE_DIR}/Ralts/lib)
set(3RDPATH ${PROJECT_SOURCE_DIR}/Ralts/3rdParty)
# if(WIN32)
#     message(STATUS "Configuring for Windows!")
# elseif(APPLE)
#     message(STATUS "Configuring for macOS!")
# endif()

include_directories(
    Ralts/3rdParty/glfw/include
    Ralts/3rdParty/glad/include
    Ralts/3rdParty/
    Ralts/3rdParty/assimp/include
    )

add_subdirectory(Ralts/3rdParty/glfw)
add_subdirectory(Ralts/3rdParty/glad)
add_subdirectory(Ralts/3rdParty/assimp)


add_subdirectory(Ralts/src/Engine)
add_subdirectory(Ralts/src/App)
add_subdirectory(Ralts/src)



