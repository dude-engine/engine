//
// Created by Jonathan Picques on 12-Dec-17.
// Copyright (c) 2017 Jonathan Picques. All rights reserved.
//

#include <dude/entity/transform.hpp>

namespace dude {

    auto transform::set_parent(dude::transform *parent) -> void {
        _parent = parent;
    }

    auto transform::get_parent() -> dude::transform * {
        return _parent;
    }

    auto transform::get_parent() const -> dude::transform const * {
        return _parent;
    }

    auto transform::get_scale(dude::transform::coord_space const &coord_space) const -> transform::scale_t {
        return _scale;
    }

    auto transform::get_position(dude::transform::coord_space const &coord_space) const -> transform::position_t {
        return _position;
    }

    auto transform::get_rotation(dude::transform::coord_space const &coord_space) const -> transform::rotation_t {
        return _rotation;
    }

}