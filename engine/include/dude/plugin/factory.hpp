//
// Created by Jonathan Picques on 05/11/2016.
//

#pragma once

#include <memory>
#include <string>
#include <functional>
#include <unordered_map>

#include <dude/plugin/manager.hpp>
#include <dude/plugin/behavior.hpp>

namespace dude { class engine; }
namespace dude { class entity; }

namespace dude {

    class plugin_factory {
    public:
        using engine_t = dude::engine *;
        using entity_t = dude::entity *;
        using manager_creator_pointer_t = dude::manager *(*)(engine_t);
        using manager_creator_func_t = std::function<dude::manager *(engine_t)>;
        using manager_creators_t = std::unordered_map<std::string, manager_creator_func_t>;
        using behavior_creator_pointer_t = dude::behavior *(*)(entity_t);
        using behavior_creator_func_t = std::function<dude::behavior *(entity_t)>;
        using behavior_creators_t = std::unordered_map<std::string, behavior_creator_func_t>;

    public:
        plugin_factory() = default;
        ~plugin_factory() = default;

    public:
        template<typename T> auto register_manager(std::string const &) -> void;
        template<typename T> auto register_behavior(std::string const &) -> void;

    public:
        auto register_manager(std::string const &, std::string const &) -> void;
        auto register_behavior(std::string const &, std::string const &) -> void;

    public:
        auto make_manager(std::string const &, engine_t) -> std::unique_ptr<manager>;
        auto make_behavior(std::string const &, entity_t) -> std::unique_ptr<behavior>;

    private:
        manager_creators_t _manager_creators;
        behavior_creators_t _behavior_creators;
    };

}

namespace dude {

    template<typename TManager>
    auto plugin_factory::register_manager(std::string const &manager_name) -> void {
        assert(_manager_creators.find(manager_name) == _manager_creators.end());
        _manager_creators.emplace(manager_name, [&manager_name] (engine_t manager_engine) -> manager * {
            auto manager = new TManager();
            manager->engine(manager_engine);
            manager->name(manager_name);
            return manager;
        });
    }

    template<typename TBehavior>
    auto plugin_factory::register_behavior(std::string const &behavior_name) -> void {
        assert(_behavior_creators.find(behavior_name) == _behavior_creators.end());
        _behavior_creators.emplace(behavior_name, [&behavior_name] (entity_t behavior_entity) -> behavior * {
            auto behavior = new TBehavior();
            behavior->entity(behavior_entity);
            behavior->name(behavior_name);
            return behavior;
        });
    }

}