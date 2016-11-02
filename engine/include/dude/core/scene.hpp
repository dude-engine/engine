//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <memory>
#include <vector>

namespace dude { class entity; }

namespace dude {

    class scene final {
    public:
        using name_t = std::string;
        using entities_t = std::vector<std::unique_ptr<entity>>;

    public:
        scene() = default;
        ~scene() = default;

    public:
        auto name(name_t const &) -> void;
        auto name() const -> name_t const &;

    public:
        auto entities() const -> entities_t const &;
        auto add_entity(std::string const &, std::unique_ptr<entity> &&) const -> void;
        auto remove_entity(std::string const &) const -> void;

    private:
        name_t _name;
        entities_t _entities;
    };

}