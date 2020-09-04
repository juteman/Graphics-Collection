cmake_minimum_required(VERSION 3.8)

project("Rasterization")


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(SDL2 CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)

set(SOURCES
        src/Rasterization.cpp
        src/Line.cpp
        src/Renderer.cpp
        src/Triangles.cpp)

set(INCLUDE
        include/Renderer.h
        include/Common.h
        src/Renderer.cpp)

add_executable(Rasterization ${SOURCES} ${INCLUDE})
target_include_directories(Rasterization
        PUBLIC
        include/
        )
target_link_libraries(Rasterization PRIVATE
        SDL2::SDL2
        SDL2::SDL2main
        Eigen3::Eigen
        )
