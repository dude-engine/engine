//
// Created by Jonathan Picques on 05/11/2016.
//

#include <cassert>

#include <dude/plugin/factory.hpp>
#include <dude/core/library.hpp>

namespace dude {

    auto plugin_factory::register_manager(std::string const &manager_name, std::string const &path) -> void {
        assert(_manager_creators.find(manager_name) == _manager_creators.end());
        auto manager_library = library(path);
        auto manager_creator = manager_library.symbol<manager_creator_pointer_t>("create_manager");
        _manager_creators.emplace(manager_name, manager_creator);
        // TODO: library closes here
    }

    auto plugin_factory::register_behavior(std::string const &behavior_name, std::string const &path) -> void {
        assert(_behavior_creators.find(behavior_name) == _behavior_creators.end());
        auto behavior_library = library(path);
        auto behavior_creator = behavior_library.symbol<behavior_creator_pointer_t>("create_behavior");
        _behavior_creators.emplace(behavior_name, behavior_creator);
        // TODO: library closes here
    }

    auto plugin_factory::make_manager(std::string const &manager_name, engine_t engine) -> std::unique_ptr<manager> {
        auto manager_creator = _manager_creators.find(manager_name);
        assert(manager_creator != _manager_creators.end());
        return std::unique_ptr<manager>(manager_creator->second(engine));
    }

    auto plugin_factory::make_behavior(std::string const &behavior_name, entity_t entity) -> std::unique_ptr<behavior> {
        auto behavior_creator = _behavior_creators.find(behavior_name);
        assert(behavior_creator != _behavior_creators.end());
        return std::unique_ptr<behavior>(behavior_creator->second(entity));
    }

}