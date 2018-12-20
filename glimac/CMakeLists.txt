include_directories(include)
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp *.h)
add_library(glimac ${SRC_FILES})
target_link_libraries(glimac ${ASSIMP_LIBRARIES})