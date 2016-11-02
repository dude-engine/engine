project(dude_demo_td)

set(DEMO_TARGET demo_td)

file(GLOB_RECURSE DEMO_SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE DEMO_HEADERS ${PROJECT_SOURCE_DIR}/*.hpp)

add_executable(${DEMO_TARGET} ${DEMO_SOURCES} ${DEMO_HEADERS})
target_link_libraries(${DEMO_TARGET} ${ENGINE_TARGET})
if (${CMAKE_SYSTEM_NAME} STREQUAL Emscripten)
    set_target_properties(${PLUGIN_TARGET} PROPERTIES LINK_FLAGS "-s MAIN_MODULE=2")
endif()