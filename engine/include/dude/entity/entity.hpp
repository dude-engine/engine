//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <memory>
#include <vector>
#include <string>

#include <dude/plugin/behavior.hpp>

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

    private:
        entity(entity const &) = delete;
        entity(entity &&) = delete;
        void operator=(entity const &) = delete;

    public:
        auto name() const -> name_t const &;
        auto name(name_t const &) -> void;

    public:
        auto entities() const -> entities_t const &;
        auto has_entity(std::string const &entity_name) const -> bool;
        auto add_entity(std::string const &entity_name, std::unique_ptr<entity> &&add_entity) -> void;
        auto remove_entity(std::string const &entity_name) -> void;

    public:
        auto behaviors() const -> behaviors_t const &;
        auto has_behavior(std::string const &behavior_name) const -> bool;
        auto add_behavior(std::string const &, std::unique_ptr<behavior> &&add_behavior) -> void;
        auto remove_behavior(std::string const &behavior_name) -> void;

    public:
        auto enabled() const -> bool;
        auto enable(bool enable) -> void;

    private:
        name_t _name;
        enabled_t _enabled;
        entities_t _entities;
        behaviors_t _behaviors;
    };

}