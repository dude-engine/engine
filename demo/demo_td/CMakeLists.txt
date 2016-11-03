project(dude_demo_td)

# Test target
set(DEMO_TARGET demo_td)

# Test sources
file(GLOB_RECURSE DEMO_SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE DEMO_HEADERS ${PROJECT_SOURCE_DIR}/*.hpp)

# Test executable
add_executable(${DEMO_TARGET} ${DEMO_SOURCES} ${DEMO_HEADERS})
target_link_libraries(${DEMO_TARGET} ${ENGINE_TARGET})

# Emscripten test executable
if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
    # Generate emscripten filesystem
    if (NOT "${EMSCRIPTEN_FILESYSTEM}" STREQUAL "")
        set(EMBED_FILES "--embed-files ${EMSCRIPTEN_FILESYSTEM}")
    endif ()
    set_target_properties(${DEMO_TARGET} PROPERTIES LINK_FLAGS "-s MAIN_MODULE=1 ${EMBED_FILES} ${LINK_FLAGS}")
endif ()