project(dude_test_engine)

set(TEST_TARGET test_engine)

file(GLOB_RECURSE TEST_SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE TEST_HEADERS ${PROJECT_SOURCE_DIR}/*.hpp)

add_executable(${TEST_TARGET} ${TEST_SOURCES} ${TEST_HEADERS})
target_link_libraries(${TEST_TARGET} ${ENGINE_TARGET} gtest_main)
target_include_directories(${TEST_TARGET} PUBLIC SYSTEM ${PROJECT_SOURCE_DIR}/googletest/googletest/include)
if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
    set_target_properties(${TEST_TARGET} PROPERTIES LINK_FLAGS "-s MAIN_MODULE=2")
endif()