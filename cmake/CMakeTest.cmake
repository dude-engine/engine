# Macro to compile a dude test
# The macro must be used within a cmake project, usually project(dude_${DUDE_TEST_TARGET})
# The macro assumes the test sources lie in the project source directory
macro(dude_add_test DUDE_TEST_TARGET)
    # Test sources
    file(GLOB_RECURSE DUDE_TEST_SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)
    file(GLOB_RECURSE DUDE_TEST_HEADERS ${PROJECT_SOURCE_DIR}/*.hpp)

    # Test executable
    add_executable(${DUDE_TEST_TARGET} ${DUDE_TEST_SOURCES} ${DUDE_TEST_HEADERS})
    target_link_libraries(${DUDE_TEST_TARGET} ${DUDE_ENGINE_TARGET} gtest_main)
    target_include_directories(${DUDE_TEST_TARGET} PUBLIC SYSTEM ${PROJECT_SOURCE_DIR}/googletest/googletest/include)

    # Emscripten tests executable
    if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
        # Generate emscripten filesystem
        if (NOT "${DUDE_EMSCRIPTEN_FILESYSTEM}" STREQUAL "")
            set(DUDE_EMBED_FILES "--embed-files ${DUDE_EMSCRIPTEN_FILESYSTEM}")
        endif ()
        if (NOT DUDE_EMBED_PLUGINS)
            # Do not build as main module if the plugins are embedded, this will disable loading of dynamic libraries with emscripten
            set_target_properties(${DUDE_TEST_TARGET} PROPERTIES LINK_FLAGS "-s MAIN_MODULE=1 ${DUDE_EMBED_FILES} ${LINK_FLAGS}")
        endif ()
    endif ()

    # Defines
    if (DUDE_EMBED_PLUGINS)
        target_compile_definitions(${DUDE_TEST_TARGET} PRIVATE DUDE_EMBED_PLUGINS)
    endif ()
endmacro()