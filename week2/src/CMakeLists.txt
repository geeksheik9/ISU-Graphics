cmake_minimum_required(VERSION 3.12)

project(chapter2Code)

LINK_DIRECTORIES( ${CMAKE_BINARY_DIR}/lib )
LINK_DIRECTORIES( ${CMAKE_BINARY_DIR}/bin )

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

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

find_package(GLUT REQUIRED)
if (GLUT_FOUND)
	include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
	link_libraries(${GLUT_LIBRARY})
endif()

set(COMMON_LIBS ${OPENGL_LIBRARIES} optimized ${GLUT_LIBRARY} ${GLEW_LIBRARIES})
set(COMMON_LIBS ${COMMON_LIBS} ${EXTRA_LIBS})

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

SET(APP_SRCS1
  source/example1.cpp
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

SET(APP_SRCS4b
  source/example4b.cpp
)

SET(APP_SRCS5
  source/example5.cpp
)

SET(APP_SRCS6 
  source/simpleCode1.cpp
)

SET(APP_COMMON
  common/InitShader.cpp
)

SET(APP_HDRS
	include/Angel.h
	include/CheckError.h
	include/mat.h
	include/vec.h
)

SET(APP_SHADERS
	shader/fshader21.glsl
	shader/fshader22.glsl
	shader/fshader23.glsl
	shader/fshader24.glsl
	shader/fshader24b.glsl	
	shader/fshader25.glsl			
	shader/vshader21.glsl
	shader/vshader22.glsl
	shader/vshader23.glsl
	shader/vshader24.glsl
	shader/vshader24b.glsl	
	shader/vshader25.glsl	
)

SOURCE_GROUP("Common Files" FILES
  ${APP_COMMON}
)

SOURCE_GROUP("Shader Files" FILES
  ${APP_SHADERS}
)

add_executable(example1  ${APP_SRCS1} ${APP_HDRS} ${APP_COMMON} ${APP_SHADERS})
add_executable(example2  ${APP_SRCS2} ${APP_HDRS} ${APP_COMMON} ${APP_SHADERS})
add_executable(example3  ${APP_SRCS3} ${APP_HDRS} ${APP_COMMON} ${APP_SHADERS})
add_executable(example4  ${APP_SRCS4} ${APP_HDRS} ${APP_COMMON} ${APP_SHADERS})
add_executable(example4b ${APP_SRCS4b} ${APP_HDRS} ${APP_COMMON} ${APP_SHADERS})
add_executable(example5  ${APP_SRCS5} ${APP_HDRS} ${APP_COMMON} ${APP_SHADERS})
add_executable(simpleCode1 ${APP_SRCS6} ${APP_HDRS} ${APP_COMMON} ${APP_SHADERS})

include_directories( include )

target_link_libraries(example1  ${COMMON_LIBS})
target_link_libraries(example2  ${COMMON_LIBS})
target_link_libraries(example3  ${COMMON_LIBS})
target_link_libraries(example4  ${COMMON_LIBS})
target_link_libraries(example4b ${COMMON_LIBS})
target_link_libraries(example5  ${COMMON_LIBS})
target_link_libraries(simpleCode1 ${COMMON_LIBS})

ADD_CUSTOM_TARGET(debug ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE:STRING=Debug ${project_binary_dir})
ADD_CUSTOM_TARGET(release ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE:STRING=Release ${project_binary_dir})






