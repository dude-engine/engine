project(dude_demo_td)

# Include cmake configurations
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

if (${MINGW})
    set(CMAKE_CXX_FLAGS -lmingw32)
endif ()
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
dude_add_demo(demo_td ${SDL2_LIBRARIES})