//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <memory>
#include <vector>
#include <string>

#include <dude/entity/entity.hpp>

namespace dude { class engine; }

namespace dude {

    class scene final {
    public:
        using name_t = std::string;
        using entities_t = std::vector<std::unique_ptr<entity>>;

    public:
        scene() = default;
        ~scene() = default;

    private:
        scene(scene const &) = delete;
        scene(scene &&) = delete;
        void operator=(scene const &) = delete;

    public:
        auto engine() const -> dude::engine *;
        auto engine(dude::engine * engine) -> void;

    public:
        auto name() const -> name_t const &;
        auto name(name_t const &name) -> void;

    public:
        auto entities() const -> entities_t const &;
        auto has_entity(std::string const &entity_name) const -> bool;
        auto add_entity(std::string const &entity_name, std::unique_ptr<entity> &&add_entity) -> void;
        auto remove_entity(std::string const &entity_name) -> void;

    private:
        dude::engine * _engine;
        name_t _name;
        entities_t _entities;
    };

}