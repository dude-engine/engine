cmake_minimum_required(VERSION 3.6)
project(dude)

# Dude options
option(DUDE_EMBED_PLUGINS "Embed the plugins in the engine library instead of compiling shared libraries" OFF)

# Dude engine target
set(DUDE_ENGINE_TARGET engine)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Dude engine variables
set(DUDE_ENGINE_SOURCE_DIR "${PROJECT_SOURCE_DIR}/engine/src")
set(DUDE_ENGINE_HEADER_DIR "${PROJECT_SOURCE_DIR}/engine/include")

# Dude engine sources
file(GLOB_RECURSE DUDE_ENGINE_SOURCES ${DUDE_ENGINE_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE DUDE_ENGINE_HEADERS ${DUDE_ENGINE_HEADER_DIR}/*.hpp)

# Dude engine library
add_library(${DUDE_ENGINE_TARGET} STATIC ${DUDE_ENGINE_SOURCES} ${DUDE_ENGINE_HEADERS})
set_target_properties(${DUDE_ENGINE_TARGET} PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(${DUDE_ENGINE_TARGET} ${CMAKE_DL_LIBS})
target_include_directories(${DUDE_ENGINE_TARGET} PUBLIC ${DUDE_ENGINE_HEADER_DIR})
target_include_directories(${DUDE_ENGINE_TARGET} PUBLIC ${PROJECT_SOURCE_DIR}/vendors)
target_include_directories(${DUDE_ENGINE_TARGET} PUBLIC ${PROJECT_SOURCE_DIR}/plugins)

# Dude plugins
add_subdirectory(${PROJECT_SOURCE_DIR}/plugins)

# Dude tests
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)

# Dude demos
add_subdirectory(${PROJECT_SOURCE_DIR}/demos)

# Include platform specifics
include(${PROJECT_SOURCE_DIR}/cmake/CMakePlatform.cmake)

# Embed plugins in the engine library
if (DUDE_EMBED_PLUGINS)
    target_compile_definitions(${DUDE_ENGINE_TARGET} PRIVATE DUDE_EMBED_PLUGINS)
    target_link_libraries(${DUDE_ENGINE_TARGET} ${DUDE_PLUGIN_TARGETS})
    target_include_directories(${DUDE_ENGINE_TARGET} PUBLIC ${PROJECT_SOURCE_DIR}/plugins)
endif ()