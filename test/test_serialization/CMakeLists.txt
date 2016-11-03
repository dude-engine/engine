project(dude_test_serialization)

# Test target
set(TEST_TARGET test_serialization)

# Test sources
file(GLOB_RECURSE TEST_SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE TEST_HEADERS ${PROJECT_SOURCE_DIR}/*.hpp)

# Test executable
add_executable(${TEST_TARGET} ${TEST_SOURCES} ${TEST_HEADERS})
target_link_libraries(${TEST_TARGET} ${ENGINE_TARGET} gtest_main)
target_include_directories(${TEST_TARGET} PUBLIC SYSTEM ${PROJECT_SOURCE_DIR}/googletest/googletest/include)

# Emscripten test executable
if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
    # Generate emscripten filesystem
    if (NOT "${EMSCRIPTEN_FILESYSTEM}" STREQUAL "")
        set(EMBED_FILES "--embed-files ${EMSCRIPTEN_FILESYSTEM}")
    endif ()
    set_target_properties(${TEST_TARGET} PROPERTIES LINK_FLAGS "-s MAIN_MODULE=1 ${EMBED_FILES} ${LINK_FLAGS}")
endif ()