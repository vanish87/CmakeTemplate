

find_package(assimp)
find_package(DirectXTK)
find_package(FX11)
find_package(freetype)
find_package(lua)
find_package(tinyxml2)


include_directories(
    ${ASSIMP_INCLUDE_DIR} 
    ${DIRECTXTK_INCLUDE_DIR} 
    ${FREETYPE_INCLUDE_DIR} 
    ${FX11_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
    ${TINYXML2_INCLUDE_DIR} 
    )


#link_directories(${EXTERNAL_BUILD_DIR}/lib)

set(PROJECT_ROOT_HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR})

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()


add_subdirectory(Common)

add_executable(BaseLib main.cpp)
target_link_libraries(BaseLib 
    ${ASSIMP_LIBRARIES} 
    ${DIRECTXTK_LIBRARIES} 
    ${FREETYPE_LIBRARIES} 
    ${FX11_LIBRARIES} 
    ${LUA_LIBRARIES} 
    ${TINYXML2_LIBRARIES}  
)
