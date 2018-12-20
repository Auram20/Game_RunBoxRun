include_directories(include ${ASSIMP_INCLUDE_DIRS})
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp *.h)
add_library(glimac ${SRC_FILES})
target_link_libraries(glimac ${ASSIMP_LIBRARIES})