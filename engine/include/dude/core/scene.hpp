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
        auto operator=(scene const &) -> void = delete;

    public:
        auto get_engine() const -> dude::engine *;
        auto set_engine(dude::engine *engine) -> void;

    public:
        auto get_name() const -> name_t const &;
        auto set_name(name_t const &name) -> void;

    public:
        auto get_entity(std::string const &entity_name) -> dude::entity *;
        auto get_entity(std::string const &entity_name) const -> dude::entity const *;
        auto get_entities() const -> entities_t const &;
        auto has_entity(std::string const &entity_name) const -> bool;
        auto add_entity(std::string const &entity_name) -> dude::entity *;
        auto remove_entity(std::string const &entity_name) -> void;

    private:
        dude::engine *_engine;
        name_t _name;
        entities_t _entities;
    };

}