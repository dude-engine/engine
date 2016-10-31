cmake_minimum_required(VERSION 3.6)
project(dude_test)

# Build google tests
set(BUILD_GTEST ON)
set(BUILD_GMOCK OFF)
add_subdirectory(googletest)

# Function to add a test for a folder and a name
function(dude_test TEST_FOLDER TEST_NAME)
    file(GLOB_RECURSE TEST_SOURCES ${TEST_FOLDER}/*.cpp)
    file(GLOB_RECURSE TEST_HEADERS ${TEST_FOLDER}/*.hpp)
    add_executable(${TEST_NAME} ${TEST_SOURCES} ${TEST_HEADERS})
    target_link_libraries(${TEST_NAME} ${DUDE_TARGET} gtest_main)
    target_include_directories(${TEST_NAME} PUBLIC SYSTEM ${PROJECT_SOURCE_DIR}/googletest/googletest/include)
endfunction()

# List tests
dude_test(${PROJECT_SOURCE_DIR}/test_engine test_engine)
dude_test(${PROJECT_SOURCE_DIR}/test_serialization test_serialization)