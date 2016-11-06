project(dude_demo)

# Include demo helpers
include(${CMAKE_SOURCE_DIR}/cmake/CMakeDemo.cmake)

# Build demos
add_subdirectory(${PROJECT_SOURCE_DIR}/demo_td)