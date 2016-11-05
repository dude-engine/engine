//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/core/scene.hpp>

namespace dude {

    auto scene::engine() const -> engine_t {
        return _engine;
    }

    auto scene::engine(engine_t engine) -> void {

    }

    auto scene::name() const -> name_t const & {
        return _name;
    }

    auto scene::name(name_t const &name) -> void {
        _name = name;
    }

    auto scene::entities() const -> const entities_t & {
        return _entities;
    }

    auto scene::has_entity(std::string const &entity_name) const -> bool {
        return false;
    }

    auto scene::add_entity(std::string const &entity_name, std::unique_ptr<entity> &&add_entity) -> void {

    }

    auto scene::remove_entity(std::string const &entity_name) -> void {

    }

}