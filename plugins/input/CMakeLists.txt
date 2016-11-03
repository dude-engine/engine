project(dude_plugin_input)

# Plugin target
set(DUDE_PLUGIN_TARGET plugin_input)

# Plugin variables
set(DUDE_PLUGIN_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(DUDE_PLUGIN_HEADER_DIR "${PROJECT_SOURCE_DIR}/include")

# Plugin sources
file(GLOB_RECURSE DUDE_PLUGIN_SOURCES ${DUDE_PLUGIN_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE DUDE_PLUGIN_HEADERS ${DUDE_PLUGIN_HEADER_DIR}/*.hpp)

# Plugin library
add_library(${DUDE_PLUGIN_TARGET} SHARED ${DUDE_PLUGIN_SOURCES} ${DUDE_PLUGIN_HEADERS})
target_link_libraries(${DUDE_PLUGIN_TARGET} ${DUDE_ENGINE_TARGET})
target_include_directories(${DUDE_PLUGIN_TARGET} PUBLIC ${DUDE_PLUGIN_HEADER_DIR})

# Emscripten plugin library
if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
    # Emscripten side-module for dynamic loading
    set_target_properties(${DUDE_PLUGIN_TARGET} PROPERTIES LINK_FLAGS "-s SIDE_MODULE=1")
    set_target_properties(${DUDE_PLUGIN_TARGET} PROPERTIES SUFFIX .js)

    # Export plugin dynamic library to emscripten filesystem (${CMAKE_BINARY_DIR}/plugins/libplugin_name.js@plugins/libplugin_name.js)
    file(RELATIVE_PATH DUDE_PLUGIN_RELATIVE_DIR ${CMAKE_SOURCE_DIR} ${PROJECT_SOURCE_DIR})
    set(DUDE_PLUGIN_RELATIVE_PATH ${DUDE_PLUGIN_RELATIVE_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${DUDE_PLUGIN_TARGET}.js)
    set(DUDE_PLUGIN_LIBS "${DUDE_PLUGIN_LIBS} ${CMAKE_BINARY_DIR}/${DUDE_PLUGIN_RELATIVE_PATH}@${DUDE_PLUGIN_RELATIVE_PATH}" PARENT_SCOPE)
endif ()