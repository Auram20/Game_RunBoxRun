find_package (Doxygen)

message("vectorD_SOURCE_DIR     " ${CMAKE_SOURCE_DIR})
message("vectorD_BINARY_DIR     " ${CMAKE_BINARY_DIR})
message("DOXYGEN_EXECUTABLE  " ${DOXYGEN_EXECUTABLE})

if(DOXYGEN_FOUND)
  configure_file (${CMAKE_SOURCE_DIR}/doc/Doxyfile-html.cmake ${CMAKE_BINARY_DIR}/doc/Doxyfile-html)
  add_custom_target (html ${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/doc/Doxyfile-html)
endif (DOXYGEN_FOUND)

