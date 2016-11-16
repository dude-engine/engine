project(dude_plugin_manager_input)

dude_add_plugin(manager_input)

# Link with SDL2
find_package(SDL2 REQUIRED)
target_link_libraries(manager_input ${SDL2_LIBRARIES})
target_include_directories(manager_input PUBLIC ${SDL2_INCLUDE_DIRS})