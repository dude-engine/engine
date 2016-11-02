project(dude_plugin_input)

# Plugin target
set(PLUGIN_TARGET plugin_input)

# Plugin variables
set(PLUGIN_SOURCE_FOLDER "${PROJECT_SOURCE_DIR}/src")
set(PLUGIN_HEADER_FOLDER "${PROJECT_SOURCE_DIR}/include")

# Plugin sources
file(GLOB_RECURSE PLUGIN_SOURCES ${PLUGIN_SOURCE_FOLDER}/*.cpp)
file(GLOB_RECURSE PLUGIN_HEADERS ${PLUGIN_HEADER_FOLDER}/*.hpp)

# Plugin library
add_library(${PLUGIN_TARGET} SHARED ${PLUGIN_SOURCES} ${PLUGIN_HEADERS})
target_link_libraries(${PLUGIN_TARGET} ${ENGINE_TARGET})
target_include_directories(${PLUGIN_TARGET} PUBLIC ${PLUGIN_HEADER_FOLDER})
if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
    set_target_properties(${PLUGIN_TARGET} PROPERTIES LINK_FLAGS "-s SIDE_MODULE=1")
    set_target_properties(${PLUGIN_TARGET} PROPERTIES SUFFIX .js)
endif()