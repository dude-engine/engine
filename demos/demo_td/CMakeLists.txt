project(dude_demo_td)

dude_add_demo(demo_td)

# Link with SDL2
find_package(SDL2 REQUIRED)
target_link_libraries(demo_td ${SDL2_LIBRARY})
target_include_directories(demo_td PUBLIC ${SDL2_INCLUDE_DIR})