# Macro to compile a dude plugin
# The macro must be used within a cmake project, usually project(dude_${DUDE_PLUGIN_TARGET})
# The macro assumes the plugin sources lie in the project source directory
macro(dude_add_plugin DUDE_PLUGIN_TARGET)
    # Plugin variables
    set(DUDE_PLUGIN_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
    set(DUDE_PLUGIN_HEADER_DIR "${PROJECT_SOURCE_DIR}/include")

    # Plugin sources
    file(GLOB_RECURSE DUDE_PLUGIN_SOURCES ${DUDE_PLUGIN_SOURCE_DIR}/*.cpp)
    file(GLOB_RECURSE DUDE_PLUGIN_HEADERS ${DUDE_PLUGIN_HEADER_DIR}/*.hpp)

    # Plugin library
    if (NOT DUDE_EMBED_PLUGINS)
        add_library(${DUDE_PLUGIN_TARGET} SHARED ${DUDE_PLUGIN_SOURCES} ${DUDE_PLUGIN_HEADERS})
        target_link_libraries(${DUDE_PLUGIN_TARGET} ${DUDE_ENGINE_TARGET})
        target_include_directories(${DUDE_PLUGIN_TARGET} PUBLIC ${DUDE_PLUGIN_HEADER_DIR})
    else ()
        add_library(${DUDE_PLUGIN_TARGET} STATIC ${DUDE_PLUGIN_SOURCES} ${DUDE_PLUGIN_HEADERS})
        target_link_libraries(${DUDE_PLUGIN_TARGET} ${DUDE_ENGINE_TARGET})
        target_include_directories(${DUDE_PLUGIN_TARGET} PUBLIC ${DUDE_PLUGIN_HEADER_DIR})

        # Tell ${DUDE_ENGINE_TARGET} to link the plugin targets
        set(DUDE_PLUGIN_TARGETS "${DUDE_PLUGIN_TARGETS};${DUDE_PLUGIN_TARGET}" PARENT_SCOPE)
    endif ()

    # Emscripten plugin library
    if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
        if (NOT DUDE_EMBED_PLUGINS)
            # Only configure emscripten if the plugins are built as shared libraries

            # Emscripten side-module for dynamic loading
            set_target_properties(${DUDE_PLUGIN_TARGET} PROPERTIES LINK_FLAGS "-s SIDE_MODULE=1")
            set_target_properties(${DUDE_PLUGIN_TARGET} PROPERTIES SUFFIX .js)

            # Export plugin dynamic library to emscripten filesystem (${CMAKE_BINARY_DIR}/plugins/libplugin_name.js@plugins/libplugin_name.js)
            file(RELATIVE_PATH DUDE_PLUGIN_RELATIVE_DIR ${CMAKE_SOURCE_DIR} ${PROJECT_SOURCE_DIR})
            set(DUDE_PLUGIN_RELATIVE_PATH ${DUDE_PLUGIN_RELATIVE_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${DUDE_PLUGIN_TARGET}.js)
            set(DUDE_PLUGIN_LIBS "${DUDE_PLUGIN_LIBS} ${CMAKE_BINARY_DIR}/${DUDE_PLUGIN_RELATIVE_PATH}@${DUDE_PLUGIN_RELATIVE_PATH}" PARENT_SCOPE)
        else ()
            # There is nothing to do
        endif ()
    endif ()

    # Defines
    if (DUDE_EMBED_PLUGINS)
        target_compile_definitions(${DUDE_PLUGIN_TARGET} PRIVATE DUDE_EMBED_PLUGINS)
    endif ()
endmacro()