//
// Created by Jonathan Picques on 05/11/2016.
//

#pragma once

#include <memory>
#include <string>
#include <functional>
#include <unordered_map>

#include <dude/core/library.hpp>
#include <dude/plugin/manager.hpp>
#include <dude/plugin/behavior.hpp>

namespace dude {

    class plugin_factory {
    public:
        using manager_creator_libraries_t = std::unordered_map<std::string, std::unique_ptr<library>>;
        using manager_creator_pointer_t = dude::manager *(*)();
        using manager_creator_func_t = std::function<dude::manager *()>;
        using manager_creators_t = std::unordered_map<std::string, manager_creator_func_t>;

    public:
        using behavior_creator_libraries_t = std::unordered_map<std::string, std::unique_ptr<library>>;
        using behavior_creator_pointer_t = dude::behavior *(*)();
        using behavior_creator_func_t = std::function<dude::behavior *()>;
        using behavior_creators_t = std::unordered_map<std::string, behavior_creator_func_t>;

    public:
        plugin_factory();
        ~plugin_factory() = default;

    private:
        plugin_factory(plugin_factory const &) = delete;
        plugin_factory(plugin_factory &&) = delete;
        void operator=(plugin_factory const &) = delete;

    public:
        template<typename T> auto register_manager(std::string const &manager_name) -> void;
        template<typename T> auto register_behavior(std::string const &behavior_name) -> void;

    public:
        auto register_manager(std::string const &manager_name, std::string const &manager_path) -> void;
        auto register_behavior(std::string const &behavior_name, std::string const &behavior_path) -> void;

    public:
        auto make_manager(std::string const &manager_name) -> std::unique_ptr<manager>;
        auto make_behavior(std::string const &behavior_name) -> std::unique_ptr<behavior>;

    private:
        auto register_manager(std::string const &manager_name, manager_creator_pointer_t manager_creator) -> void;
        auto register_behavior(std::string const &behavior_name, behavior_creator_pointer_t behavior_creator) -> void;

    private:
        manager_creator_libraries_t _manager_creator_libraries;
        manager_creators_t _manager_creators;
        behavior_creator_libraries_t _behavior_creator_libraries;
        behavior_creators_t _behavior_creators;
    };

}

namespace dude {

    template<typename TManager>
    auto plugin_factory::register_manager(std::string const &manager_name) -> void {
        assert(_manager_creators.find(manager_name) == _manager_creators.end());
        register_manager(manager_name, [] () -> manager * { return new TManager; });
    }

    template<typename TBehavior>
    auto plugin_factory::register_behavior(std::string const &behavior_name) -> void {
        assert(_behavior_creators.find(behavior_name) == _behavior_creators.end());
        register_behavior(behavior_name, [] () -> behavior * { return new TBehavior; });
    }

}