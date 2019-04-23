

set(target DirectXTK)


# 
# Sources
# 

set(include_path "${CMAKE_CURRENT_SOURCE_DIR}/${target}/Inc")
set(source_path  "${CMAKE_CURRENT_SOURCE_DIR}/${target}/Src")

include_directories(${include_path})
aux_source_directory(${source_path} sources)

# Build library
add_library(${target}
    ${sources}
)