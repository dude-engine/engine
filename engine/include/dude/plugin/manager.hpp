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
        using dependencies_t = std::unordered_set<std::string>;

    public:
        manager() = default;
        ~manager() override = default;

    public:
        manager(manager const &) = delete;
        manager(manager &&) = delete;
        auto operator=(manager const &) -> void = delete;

    public:
        virtual auto on_dependencies() -> dependencies_t;

    public:
        virtual auto on_start() -> void;
        virtual auto on_update() -> void;
        virtual auto on_stop() -> void;

    public:
        auto get_dependencies() const -> dependencies_t const &;

    public:
        auto configure_dependencies() -> void;

    private:
        dependencies_t _manager_dependencies;
        dependencies_t _dependencies;
    };

}