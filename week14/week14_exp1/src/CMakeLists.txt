cmake_minimum_required(VERSION 3.12)

project(week14_exp1)

LINK_DIRECTORIES( ${CMAKE_BINARY_DIR}/lib )
LINK_DIRECTORIES( ${CMAKE_BINARY_DIR}/bin )

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# For multi-config builds (e.g. msvc)
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

find_package(OpenGL REQUIRED )
if (OpenGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS})
    link_libraries(${OpenGL_LIBRARIES})
endif()	

find_package(GLM REQUIRED)
if (GLM_FOUND)
    include_directories(${GLM_INCLUDE_DIRS})
    link_libraries(${GLM_LIBRARIES})
endif()

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

find_package(GLUT REQUIRED)
if (GLUT_FOUND)
	include_directories( ${GLUT_INCLUDE_DIRS} )
	link_libraries(${GLUT_LIBRARY})
endif()

find_package(GLFW REQUIRED)
include_directories(${GLFW_INCLUDE_DIR})
link_libraries(${GLFW_LIBRARIES})

find_package(GLAD REQUIRED)
include_directories(${GLAD_INCLUDE_PATH})
link_libraries(${GLAD_LIBRARIES})

find_package(STBI REQUIRED)
include_directories(${STBI_INCLUDE_DIR})
link_libraries(${STBI_LIBRARY})

set(COMMON_LIBS optimized ${OpenGL_LIBRARIES} ${GLUT_LIBRARY} 
${GLEW_LIBRARIES} ${GLFW_LIBRARIES} ${STBI_LIBRARY} ${GLM_LIBRARIES})
set(COMMON_LIBS ${COMMON_LIBS} ${EXTRA_LIBS})

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

SET(APP_SRCS1a
  source/example1a.cpp
)

SET(APP_SRCS1b
  source/example1b.cpp
)

SET(APP_SRCS1c
  source/example1c.cpp
)

SET(APP_SRCS2
  source/example2.cpp
)

SET(APP_SRCS3
  source/example3.cpp
)

SET(APP_SRCS4
  source/example4.cpp
)

SET(APP_COMMON
  common/loadShaders.cpp
)

SET(APP_HDRS
	include/mat.h
	include/vec.h
	include/loadShaders.h
	include/camera.h
)

SET(APP_SHADERS1a
	shader/5.1a.light_casters.vert
	shader/5.1a.light_casters.frag
	shader/5.1a.lamp.vert
	shader/5.1a.lamp.frag
)

SET(APP_SHADERS1b
	shader/lighting_maps1b.vert
	shader/lighting_maps1b.frag
	shader/lamp1b.vert
	shader/lamp1b.frag
)

SET(APP_SHADERS1c
	shader/lighting_maps1c.vert
	shader/lighting_maps1c.frag
	shader/lamp1c.vert
	shader/lamp1c.frag
)

SET(APP_SHADERS2
	shader/5.2.light_casters.vert
	shader/5.2.light_casters.frag
	shader/5.2.lamp.vert
	shader/5.2.lamp.frag
)

SET(APP_SHADERS3
	shader/5.3.light_casters.vert
	shader/5.3.light_casters.frag
	shader/5.3.lamp.vert
	shader/5.3.lamp.frag
)

SET(APP_SHADERS4
	shader/5.4.light_casters.vert
	shader/5.4.light_casters.frag
	shader/5.4.lamp.vert
	shader/5.4.lamp.frag
)


SOURCE_GROUP("Common Files" FILES
  ${APP_COMMON}
)

SOURCE_GROUP("Shader Files" FILES
 ${APP_SHADERS1a} 
 ${APP_SHADERS1b}  
 ${APP_SHADERS1c}  
 ${APP_SHADERS2} 
 ${APP_SHADERS3} 
 ${APP_SHADERS4}  
)

add_executable(example1a  ${APP_SRCS1a} ${APP_COMMON}  ${APP_HDRS}  ${APP_SHADERS1a})
target_link_libraries(example1a  ${COMMON_LIBS})

add_executable(example1b  ${APP_SRCS1b} ${APP_COMMON}  ${APP_HDRS}  ${APP_SHADERS1b})
target_link_libraries(example1b  ${COMMON_LIBS})

add_executable(example1c  ${APP_SRCS1c} ${APP_COMMON}  ${APP_HDRS}  ${APP_SHADERS1c})
target_link_libraries(example1c  ${COMMON_LIBS})

add_executable(example2  ${APP_SRCS2} ${APP_COMMON}  ${APP_HDRS}  ${APP_SHADERS2})
target_link_libraries(example2  ${COMMON_LIBS})

add_executable(example3  ${APP_SRCS3} ${APP_COMMON}  ${APP_HDRS}  ${APP_SHADERS3})
target_link_libraries(example2  ${COMMON_LIBS})

add_executable(example4  ${APP_SRCS4} ${APP_COMMON}  ${APP_HDRS}  ${APP_SHADERS4})
target_link_libraries(example4  ${COMMON_LIBS})

include_directories( include )

ADD_CUSTOM_TARGET(debug ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE:STRING=Debug ${project_binary_dir})
ADD_CUSTOM_TARGET(release ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE:STRING=Release ${project_binary_dir})






