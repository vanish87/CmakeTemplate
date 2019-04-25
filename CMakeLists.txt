cmake_minimum_required(VERSION 2.8)


# Include cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Register general cmake commands
include(cmake/Custom.cmake)

# Cmake module
include(GenerateExportHeader)

set(WriterCompilerDetectionHeaderFound NOTFOUND)
# This module is only available with CMake >=3.1, so check whether it could be found
# BUT in CMake 3.1 this module doesn't recognize AppleClang as compiler, so just use it as of CMake 3.2
if (${CMAKE_VERSION} VERSION_GREATER "3.2")
    include(WriteCompilerDetectionHeader OPTIONAL RESULT_VARIABLE WriterCompilerDetectionHeaderFound)
endif()

set(EXTERNAL_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/External/ExternalBuilds")
set(EXTERNAL_PRE_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source/ExternalLibs/ManualBuild")

set (CMAKE_CXX_STANDARD 11)

project(vEngine)

add_subdirectory(Source)
