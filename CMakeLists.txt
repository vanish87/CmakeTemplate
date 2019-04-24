cmake_minimum_required(VERSION 2.8)


# Include cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(EXTERNAL_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/External/ExternalBuilds")
set(EXTERNAL_PRE_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source/ExternalLibs/ManualBuild")

set (CMAKE_CXX_STANDARD 11)

project(vEngine)

add_subdirectory(Source)
