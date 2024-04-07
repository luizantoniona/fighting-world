cmake_minimum_required(VERSION 3.15.0)
project(MFW VERSION 0.1.0 LANGUAGES C CXX)

include_directories( ${includes} ) 

add_executable(MFW main.cpp ${SOURCES})

set(EXTERNAL_LIBRARIES
sfml-system
sfml-graphics
sfml-window
sqlite3
)

target_link_libraries(MFW PRIVATE ${EXTERNAL_LIBRARIES} )

add_subdirectory(Components)
add_subdirectory(Database)
add_subdirectory(Manager)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}") 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
