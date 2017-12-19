project(dude_test)

# Build google tests
set(BUILD_GTEST ON)
set(BUILD_GMOCK OFF)
add_subdirectory(googletest)

# Include test helpers
include(${CMAKE_SOURCE_DIR}/assets/cmake/CMakeTest.cmake)

# Build tests
add_subdirectory(${PROJECT_SOURCE_DIR}/test_engine)
add_subdirectory(${PROJECT_SOURCE_DIR}/test_manager)
add_subdirectory(${PROJECT_SOURCE_DIR}/test_property)
add_subdirectory(${PROJECT_SOURCE_DIR}/test_serialization)
