project(dude_plugins_managers)

# Build plugins
add_subdirectory(${PROJECT_SOURCE_DIR}/input)

# Export plugins for emscripten filesystem
if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
    set(DUDE_EMSCRIPTEN_FILESYSTEM ${DUDE_PLUGIN_LIBS} PARENT_SCOPE)
endif ()