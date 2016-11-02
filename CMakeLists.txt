cmake_minimum_required(VERSION 3.6)
project(dude)

# Dude engine target
set(ENGINE_TARGET engine)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Dude engine variables
set(ENGINE_SOURCE_FOLDER "${PROJECT_SOURCE_DIR}/engine/src")
set(ENGINE_HEADER_FOLDER "${PROJECT_SOURCE_DIR}/engine/include")

# Dude engine sources
file(GLOB_RECURSE ENGINE_SOURCES ${ENGINE_SOURCE_FOLDER}/*.cpp)
file(GLOB_RECURSE ENGINE_HEADERS ${ENGINE_HEADER_FOLDER}/*.hpp)

# Dude engine library
add_library(${ENGINE_TARGET} STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})
set_target_properties(${ENGINE_TARGET} PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(${ENGINE_TARGET} ${CMAKE_DL_LIBS})
target_include_directories(${ENGINE_TARGET} PUBLIC ${ENGINE_HEADER_FOLDER})
target_include_directories(${ENGINE_TARGET} PUBLIC ${PROJECT_SOURCE_DIR}/vendors)

# Dude plugins
add_subdirectory(${PROJECT_SOURCE_DIR}/plugins)

# Dude tests
add_subdirectory(${PROJECT_SOURCE_DIR}/test)

# Dude demos
add_subdirectory(${PROJECT_SOURCE_DIR}/demo)