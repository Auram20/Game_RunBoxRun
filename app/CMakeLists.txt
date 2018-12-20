include_directories(include)
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
add_library(app ${SRC_FILES})
add_dependencies(app game glimac)
