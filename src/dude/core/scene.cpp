//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/core/scene.hpp>

namespace dude {

    auto scene::entities() const -> const scene::entities_t & {
        return _entities;
    }

    auto scene::add_entity(std::string const &, std::unique_ptr<entity> &&) const -> void {

    }

    auto scene::remove_entity(std::string const &) const -> void {

    }
}