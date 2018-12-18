cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# give a name to the project
project(RunBoxRun)

# use at least c++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# compilation flags (should be avoided)
set(CMAKE_CXX_FLAGS "-Wall -O2")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")


# set(CMAKE_CACHEFILE_DIR  ${PROJECT_BINARY_DIR}/caches)


# specify the system
# see: https://cmake.org/cmake/help/v3.9/manual/cmake-variables.7.html
message("CMAKE_VERSION          : " ${CMAKE_VERSION})
message("CMAKE_SYSTEM_NAME      : " ${CMAKE_SYSTEM_NAME})
message("CMAKE_SYSTEM           : " ${CMAKE_SYSTEM})
message("CMAKE_SYSTEM_PROCESSOR : " ${CMAKE_SYSTEM_PROCESSOR})

# specify the directories
message("CMAKE_BINARY_DIR       : " ${CMAKE_BINARY_DIR})
message("CMAKE_SOURCE_DIR       : " ${CMAKE_SOURCE_DIR})
message("CMAKE_HOME_DIRECTORY   : " ${CMAKE_HOME_DIRECTORY})
message("PROJECT_BINARY_DIR     : " ${PROJECT_BINARY_DIR})
message("PROJECT_SOURCE_DIR     : " ${PROJECT_SOURCE_DIR})

# prevent bad move
if(NOT ${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR}/build)
    message( FATAL_ERROR "It must be in the build folder of your source folder !" )
endif()

# add a "output" directory in the project binary directory
# file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR})

# put the binary files in this directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# package
find_package(SDL REQUIRED)
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} glimac/include game/include utils/include)

set(ALL_LIBRARIES game glimac utils ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})



# If we have compiler requirements for this library, list them here
#target_compile_features([NOM_DU_PROJET] 
#    PUBLIC cxx_auto_type
#    PRIVATE cxx_variadic_templates)

add_subdirectory(glimac)
add_subdirectory(game)
add_subdirectory(utils)


# compiler
file(GLOB HEADER_FILES *.hpp)
file(GLOB SRC_FILES *.cpp)

add_executable(runBoxRun ${CMAKE_SOURCE_DIR}/main.cpp)
target_link_libraries(runBoxRun ${ALL_LIBRARIES})

# specify the library lib path
#target_link_libraries(stabilisation ${OpenCV_LIBS})


# call the CMakeLists.txt to make the documentation (Doxygen)
# > 'make html' to generate the documentation
# > the documentation is located in : [CMAKE ROOT]/build/doc/doc-doxygen/html
add_subdirectory(doc)




