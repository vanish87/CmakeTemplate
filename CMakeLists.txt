cmake_minimum_required(VERSION 2.8)

# Meta information about the project
set(META_PROJECT_NAME        "vEngine")
set(META_PROJECT_DESCRIPTION "CMake Project Template")
set(META_AUTHOR_ORGANIZATION "CG Internals GmbH")
set(META_AUTHOR_DOMAIN       "https://github.com/cginternals/cmake-init/")
set(META_AUTHOR_MAINTAINER   "opensource@cginternals.com")
set(META_VERSION_MAJOR       "2")
set(META_VERSION_MINOR       "0")
set(META_VERSION_PATCH       "0")
set(META_VERSION_REVISION    "${GIT_REV}")
set(META_VERSION             "${META_VERSION_MAJOR}.${META_VERSION_MINOR}.${META_VERSION_PATCH}")
set(META_NAME_VERSION        "${META_PROJECT_NAME} v${META_VERSION} (${META_VERSION_REVISION})")
set(META_CMAKE_INIT_SHA      "${GIT_REV}")

string(MAKE_C_IDENTIFIER ${META_PROJECT_NAME} META_PROJECT_ID)
string(TOUPPER ${META_PROJECT_ID} META_PROJECT_ID)


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

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

set (CMAKE_CXX_STANDARD 11)

# Generate folders for IDE targets (e.g., VisualStudio solutions)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(IDE_FOLDER "")

# 
# Project configuration options
# 

# Project options
option(BUILD_SHARED_LIBS      "Build shared instead of static libraries."              ON)

# Generate version-header
configure_file(version.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/${META_PROJECT_NAME}/${META_PROJECT_NAME}-version.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/)

# Create version file
#file(WRITE "${PROJECT_BINARY_DIR}/VERSION" "${META_NAME_VERSION}")

# 
# Declare project
# 
project(${META_PROJECT_NAME} C CXX)


add_subdirectory(Source)
