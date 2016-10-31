cmake_minimum_required(VERSION 3.6)
project(dude)

# Dude engine target
set(DUDE_TARGET dude)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Dude engine options
option(DUDE_ENGINE_LIBRARY "Dude engine static library" ON)
option(DUDE_ENGINE_BUILD_DEMO "Build dude demos" ON)
option(DUDE_ENGINE_BUILD_TEST "Build dude tests" ON)

# Dude sources and headers
file(GLOB_RECURSE DUDE_ENGINE_SOURCE ${CMAKE_SOURCE_DIR}/src/dude/*.cpp)
file(GLOB_RECURSE DUDE_ENGINE_HEADER ${CMAKE_SOURCE_DIR}/include/dude/*.hpp)
# Dude vendors sources
file(GLOB_RECURSE DUDE_ENGINE_RAPIDJSON ${CMAKE_SOURCE_DIR}/vendors/rapidjson/*.h)

# Dude engine library
add_library(${DUDE_TARGET} STATIC ${DUDE_ENGINE_SOURCE} ${DUDE_ENGINE_HEADER} ${DUDE_ENGINE_RAPIDJSON})

# Dude engine includes
target_include_directories(${DUDE_TARGET} PUBLIC ${CMAKE_SOURCE_DIR}/include)
# Dude vendors includes
target_include_directories(${DUDE_TARGET} PUBLIC ${CMAKE_SOURCE_DIR}/vendors)

# Build dude demos
if (DUDE_ENGINE_BUILD_DEMO)
    add_subdirectory(${CMAKE_SOURCE_DIR}/asset/demo)
endif ()

# Build google tests
if (DUDE_ENGINE_BUILD_TEST)
    add_subdirectory(${CMAKE_SOURCE_DIR}/asset/test)
endif ()