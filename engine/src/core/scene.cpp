//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/core/scene.hpp>

namespace dude {

    auto scene::engine() const -> dude::engine * {
        return _engine;
    }

    auto scene::engine(dude::engine *engine) -> void {

    }

    auto scene::name() const -> name_t const & {
        return _name;
    }

    auto scene::name(name_t const &name) -> void {
        _name = name;
    }

    auto scene::entity(std::string const &entity_name) -> dude::entity * {
        return nullptr;
    }

    auto scene::entity(std::string const &entity_name) const -> dude::entity const * {
        return nullptr;
    }

    auto scene::entities() const -> const entities_t & {
        return _entities;
    }

    auto scene::has_entity(std::string const &entity_name) const -> bool {
        return false;
    }

    auto scene::add_entity(std::string const &entity_name) -> dude::entity * {
        return nullptr;
    }

    auto scene::remove_entity(std::string const &entity_name) -> void {

    }

}