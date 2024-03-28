cmake_minimum_required(VERSION 3.15.0)
project(MFW VERSION 0.1.0 LANGUAGES C CXX)

include_directories( ${includes} ) 

add_executable(MFW main.cpp ${SOURCES})

target_link_libraries(MFW PRIVATE sfml-system sfml-graphics sfml-window )

add_subdirectory(Components)
add_subdirectory(Components/Window)
add_subdirectory(Thread)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}") 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
