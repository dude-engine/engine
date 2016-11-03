project(dude_plugins)

# Build plugins
add_subdirectory(${PROJECT_SOURCE_DIR}/input)

# Export plugins for emscripten filesystem
if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
    set(EMSCRIPTEN_FILESYSTEM ${PLUGINS_LIBRARIES} PARENT_SCOPE)
endif ()