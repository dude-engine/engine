//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <string>
#include <unordered_set>

#include <dude/system.hpp>
#include <dude/plugin/plugin.hpp>

namespace dude { class entity; }

namespace dude {

    class DUDE_API behavior : public plugin {
    public:
        using dependencies_t = std::unordered_set<std::string>;

    public:
        behavior() = default;
        virtual ~behavior() = default;

    private:
        behavior(behavior const &) = delete;
        behavior(behavior &&) = delete;
        auto operator=(behavior const &) -> void = delete;

    public:
        virtual auto on_manager_dependencies() -> dependencies_t;
        virtual auto on_dependencies() -> dependencies_t;

    public:
        virtual auto on_start() -> void;
        virtual auto on_update() -> void;
        virtual auto on_stop() -> void;

    public:
        auto get_entity() const -> dude::entity *;
        auto set_entity(dude::entity *entity) -> void;

    public:
        auto get_manager_dependencies() const -> dependencies_t const &;
        auto get_dependencies() const -> dependencies_t const &;

    public:
        auto configure_manager_dependencies() -> void;
        auto configure_dependencies() -> void;

    private:
        dude::entity *_entity;
        dependencies_t _manager_dependencies;
        dependencies_t _dependencies;
    };

}