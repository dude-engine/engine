project(dude_test)

# Build google tests
set(BUILD_GTEST ON)
set(BUILD_GMOCK OFF)
add_subdirectory(googletest)

# Include test utils
include(${CMAKE_SOURCE_DIR}/cmake/CMakeTest.cmake)

# Build tests
add_subdirectory(${PROJECT_SOURCE_DIR}/test_engine)
add_subdirectory(${PROJECT_SOURCE_DIR}/test_serialization)
add_subdirectory(${PROJECT_SOURCE_DIR}/test_plugin_factory)