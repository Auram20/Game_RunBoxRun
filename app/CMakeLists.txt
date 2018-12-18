include_directories(include ${GLIMAC_INCLUDE_DIR} ${GAME_INCLUDE_DIR})
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
add_library(app ${SRC_FILES})
