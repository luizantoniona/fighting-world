cmake_minimum_required(VERSION 3.15.0)
project(MFW VERSION 0.1.0 LANGUAGES C CXX)

find_package( OpenGL REQUIRED )
find_package( GLFW3 REQUIRED )

include_directories( ${includes} ) 

add_executable(MFW main.cpp ${SOURCES})

target_link_libraries(MFW PRIVATE glfw3 opengl32 )

add_subdirectory(window)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
