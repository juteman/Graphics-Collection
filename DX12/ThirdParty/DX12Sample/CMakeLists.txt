cmake_minimum_required(VERSION 3.8)
project(DXSample CXX)
file(GLOB SOURCE "src/*.cpp")

add_library(DXSample
${SOURCE}
)

target_include_directories(
DXSample
PUBLIC
include/
)
