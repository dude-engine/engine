//
// Created by Jonathan Picques on 31/10/2016.
//

#include <cassert>

#include <dude/core/scene.hpp>

namespace dude {

    auto scene::name(name_t const &name) -> void {
        assert(_name.empty());
        _name = name;
    }

    auto scene::name() const -> name_t const & {
        assert(!_name.empty());
        return _name;
    }

    auto scene::entities() const -> const scene::entities_t & {
        return _entities;
    }

    auto scene::add_entity(std::string const &, std::unique_ptr<entity> &&) const -> void {

    }

    auto scene::remove_entity(std::string const &) const -> void {

    }

}