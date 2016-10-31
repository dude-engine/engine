cmake_minimum_required(VERSION 3.6)
project(dude_demo)

# Function to add a demo for a folder and a name
function(dude_demo DEMO_FOLDER DEMO_NAME)
    file(GLOB_RECURSE DEMO_SOURCES ${DEMO_FOLDER}/*.cpp)
    file(GLOB_RECURSE DEMO_HEADERS ${DEMO_FOLDER}/*.hpp)
    add_executable(${DEMO_NAME} ${DEMO_SOURCES} ${DEMO_HEADERS})
    target_link_libraries(${DEMO_NAME} ${DUDE_TARGET})
endfunction()

# List demos
dude_demo(${PROJECT_SOURCE_DIR}/tower_defense demo_tower_defense)
