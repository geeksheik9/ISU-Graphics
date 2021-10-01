#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "stb::image" for configuration "MinSizeRel"
set_property(TARGET stb::image APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(stb::image PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "C"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/stb-image.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS stb::image )
list(APPEND _IMPORT_CHECK_FILES_FOR_stb::image "${_IMPORT_PREFIX}/lib/stb-image.lib" )

# Import target "stb::image-write" for configuration "MinSizeRel"
set_property(TARGET stb::image-write APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(stb::image-write PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "C"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/stb-image-write.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS stb::image-write )
list(APPEND _IMPORT_CHECK_FILES_FOR_stb::image-write "${_IMPORT_PREFIX}/lib/stb-image-write.lib" )

# Import target "stb::image-resize" for configuration "MinSizeRel"
set_property(TARGET stb::image-resize APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(stb::image-resize PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "C"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/stb-image-resize.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS stb::image-resize )
list(APPEND _IMPORT_CHECK_FILES_FOR_stb::image-resize "${_IMPORT_PREFIX}/lib/stb-image-resize.lib" )

# Import target "stb::perlin" for configuration "MinSizeRel"
set_property(TARGET stb::perlin APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(stb::perlin PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "C"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/stb-perlin.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS stb::perlin )
list(APPEND _IMPORT_CHECK_FILES_FOR_stb::perlin "${_IMPORT_PREFIX}/lib/stb-perlin.lib" )

# Import target "stb::vorbis" for configuration "MinSizeRel"
set_property(TARGET stb::vorbis APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(stb::vorbis PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "C"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/stb-vorbis.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS stb::vorbis )
list(APPEND _IMPORT_CHECK_FILES_FOR_stb::vorbis "${_IMPORT_PREFIX}/lib/stb-vorbis.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
