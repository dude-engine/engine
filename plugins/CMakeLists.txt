project(dude_plugins)

# Include plugin helpers
include(${CMAKE_SOURCE_DIR}/cmake/CMakePlugin.cmake)

# Build managers
add_subdirectory(${PROJECT_SOURCE_DIR}/managers)

# Build behaviors
add_subdirectory(${PROJECT_SOURCE_DIR}/behaviors)

# Embed plugins in the engine library
if (DUDE_EMBED_PLUGINS)
    # Tell ${DUDE_ENGINE_TARGET} to link the plugin targets
    set(DUDE_PLUGIN_TARGETS ${DUDE_PLUGIN_TARGETS} PARENT_SCOPE)
endif ()

# Export plugins for emscripten filesystem
if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
    if (NOT DUDE_EMBED_PLUGINS)
        # Populate the emscripten filesystem if the plugins are built as shared libraries
        set(DUDE_EMSCRIPTEN_FILESYSTEM ${DUDE_EMSCRIPTEN_FILESYSTEM} PARENT_SCOPE)
    endif ()
endif ()