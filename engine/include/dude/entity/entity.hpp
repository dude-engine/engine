//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <memory>
#include <vector>
#include <string>

#include <dude/plugin/behavior.hpp>

namespace dude { class scene; }

namespace dude {

    class entity final {
    public:
        using name_t = std::string;
        using enabled_t = bool;
        using entities_t = std::vector<std::unique_ptr<entity>>;
        using behaviors_t = std::vector<std::unique_ptr<behavior>>;

    public:
        entity() = default;
        ~entity() = default;

    public:
        entity(entity const &) = delete;
        entity(entity &&) = delete;
        auto operator=(entity const &) -> void = delete;

    public:
        auto get_scene() const -> dude::scene *;
        auto set_scene(dude::scene *scene) -> void;

    public:
        auto get_parent() const -> dude::entity *;
        auto set_parent(dude::entity *parent) -> void;

    public:
        auto get_name() const -> name_t const &;
        auto set_name(name_t const &) -> void;

    public:
        auto get_child(std::string const &child_name) -> dude::entity *;
        auto get_child(std::string const &child_name) const -> dude::entity const *;
        auto get_children() const -> entities_t const &;
        auto has_child(std::string const &child_name) const -> bool;
        auto add_child(std::string const &child_name) -> dude::entity *;
        auto remove_child(std::string const &child_name) -> void;

    public:
        auto get_behaviors() const -> behaviors_t const &;
        auto get_behavior(std::string const &behavior_name) -> dude::behavior *;
        auto get_behavior(std::string const &behavior_name) const -> dude::behavior const *;
        auto has_behavior(std::string const &behavior_name) const -> bool;
        auto add_behavior(std::string const &behavior_name) -> dude::behavior *;
        auto remove_behavior(std::string const &behavior_name) -> void;

    public:
        auto is_enabled() const -> bool;
        auto set_enabled(bool enabled) -> void;

    private:
        dude::scene *_scene = nullptr;
        dude::entity *_parent = nullptr;
        name_t _name;
        enabled_t _enabled = false;
        entities_t _children;
        behaviors_t _behaviors;
    };

}