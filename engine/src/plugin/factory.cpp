//
// Created by Jonathan Picques on 05/11/2016.
//

#include <cassert>

#include <dude/plugin/factory.hpp>

#if defined(DUDE_EMBED_PLUGINS)
    #include <managers/input/include/input/input.hpp>
#endif

namespace dude {

    plugin_factory::plugin_factory() {
        #if defined(DUDE_EMBED_PLUGINS)
            register_manager<dude::input>("input");
        #endif
    }

    auto plugin_factory::register_manager(std::string const &manager_name, std::string const &manager_path) -> void {
        assert(_manager_creators.find(manager_name) == _manager_creators.end());
        auto manager_library = std::make_unique<library>(manager_path);
        auto manager_creator = manager_library->symbol<manager_creator_pointer_t>("create_manager");
        register_manager(manager_name, manager_creator);
        _manager_creator_libraries.emplace(manager_name, std::move(manager_library));
    }

    auto plugin_factory::register_behavior(std::string const &behavior_name, std::string const &behavior_path) -> void {
        assert(_behavior_creators.find(behavior_name) == _behavior_creators.end());
        auto behavior_library = std::make_unique<library>(behavior_path);
        auto behavior_creator = behavior_library->symbol<behavior_creator_pointer_t>("create_behavior");
        register_behavior(behavior_name, behavior_creator);
        _behavior_creator_libraries.emplace(behavior_name, std::move(behavior_library));
    }

    auto plugin_factory::make_manager(std::string const &manager_name) -> std::unique_ptr<manager> {
        auto manager_creator = _manager_creators.find(manager_name);
        assert(manager_creator != _manager_creators.end());
        return std::unique_ptr<manager>(manager_creator->second());
    }

    auto plugin_factory::make_behavior(std::string const &behavior_name) -> std::unique_ptr<behavior> {
        auto behavior_creator = _behavior_creators.find(behavior_name);
        assert(behavior_creator != _behavior_creators.end());
        return std::unique_ptr<behavior>(behavior_creator->second());
    }

    auto plugin_factory::register_manager(std::string const &manager_name, manager_creator_pointer_t manager_creator) -> void {
        _manager_creators.emplace(manager_name, [manager_name, manager_creator] () -> manager * {
            auto manager = manager_creator();
            manager->name(manager_name);
            return manager;
        });
    }

    auto plugin_factory::register_behavior(std::string const &behavior_name, behavior_creator_pointer_t behavior_creator) -> void {
        _behavior_creators.emplace(behavior_name, [behavior_name, behavior_creator] () -> behavior * {
            auto behavior = behavior_creator();
            behavior->name(behavior_name);
            return behavior;
        });
    }

}