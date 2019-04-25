
# 
# External dependencies
# 

# find_package(THIRDPARTY REQUIRED)


# 
# Library name and options
# 

# Target name
set(target CommonLib)

# Exit here if required dependencies are not met
message(STATUS "Lib ${target}")

# Set API export file and macro
#string(MAKE_C_IDENTIFIER ${target} target_id)
#string(TOUPPER ${target_id} target_id)
#set(feature_file         "include/${target}/${target}_features.h")
#set(export_file          "include/${target}/${target}_export.h")
#set(template_export_file "include/${target}/${target}_api.h")
#set(export_macro         "${target_id}_API")


# 
# Sources
# 

set(include_path ${CMAKE_CURRENT_SOURCE_DIR}/Header)
set(source_path  ${CMAKE_CURRENT_SOURCE_DIR}/Source)

file(GLOB headers
    ${include_path}/*.h
)

file(GLOB sources
    ${source_path}/*.cpp
)

# Group source files
set(header_group "Header Files (API)")
set(source_group "Source Files")
source_group_by_path(${include_path} "\\\\.h$|\\\\.hpp$" 
   ${header_group} ${headers})
source_group_by_path(${source_path}  "\\\\.cpp$|\\\\.c$|\\\\.h$|\\\\.hpp$" 
   ${source_group} ${sources})


# 
# Create library
# 

# Build library
add_library(${target}
    ${sources}
)

# Create namespaced alias
add_library(${META_PROJECT_NAME}::${target} ALIAS ${target})

#Use export to make this lib visiable for other projects
#export(TARGETS ${target} NAMESPACE ${META_PROJECT_NAME}:: FILE ${PROJECT_BINARY_DIR}/cmake/${target}/${target}-export.cmake)


target_include_directories(${target} 
    PRIVATE 
    ${PROJECT_ROOT_HEADER_PATH}
    ${TINYXML2_INCLUDE_DIR}
)

