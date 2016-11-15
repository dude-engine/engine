project(dude_plugin_manager_window)

dude_add_plugin(manager_window)

# Link with SDL2
find_package(SDL2 REQUIRED)
target_link_libraries(manager_window ${SDL2_LIBRARY})
target_include_directories(manager_window PUBLIC ${SDL2_INCLUDE_DIR})