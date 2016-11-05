//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <string>
#include <unordered_set>

#include <dude/system.hpp>
#include <dude/plugin/plugin.hpp>

namespace dude {

    class DUDE_API manager : public plugin {
    public:
        using enabled_t = bool;
        using dependencies_t = std::unordered_set<std::string>;

    public:
        manager() = default;
        virtual ~manager() = default;

    private:
        manager(manager const &) = delete;
        manager(manager &&) = delete;
        void operator=(manager const &) = delete;

    public:
        virtual auto on_manager_dependencies() -> dependencies_t;
        virtual auto on_dependencies() -> dependencies_t;

    public:
        virtual auto on_enable() -> void;
        virtual auto on_start() -> void;
        virtual auto on_update() -> void;
        virtual auto on_stop() -> void;
        virtual auto on_disable() -> void;

    public:
        auto manager_dependencies() const -> dependencies_t const &;
        auto dependencies() const -> dependencies_t const &;

    public:
        auto configure_manager_dependencies() -> void;
        auto configure_dependencies() -> void;

    private:
        dependencies_t _manager_dependencies;
        dependencies_t _dependencies;
    };

}