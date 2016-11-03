project(dude_plugins)

# Build managers
add_subdirectory(${PROJECT_SOURCE_DIR}/managers)

# Export plugins for emscripten filesystem
if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
    set(DUDE_EMSCRIPTEN_FILESYSTEM ${DUDE_EMSCRIPTEN_FILESYSTEM} PARENT_SCOPE)
endif ()