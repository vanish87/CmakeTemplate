IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/libs CACHE PATH "set external" FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

add_subdirectory(assimp)
add_subdirectory(freetype2)
add_subdirectory(lua)

#build directxtex and FX11 mannully
#add_subdirectory(directxtex)
#add_subdirectory(FX11)
