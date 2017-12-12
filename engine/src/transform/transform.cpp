//
// Created by Jonathan Picques on 12-Dec-17.
// Copyright (c) 2017 Jonathan Picques. All rights reserved.
//

#include <dude/transform/transform.hpp>

namespace dude {

    auto transform::set_entity(dude::entity *entity) -> void {
        _entity = entity;
    }

    auto transform::get_entity() -> dude::entity * {
        return _entity;
    }

    auto transform::get_entity() const -> dude::entity const * {
        return _entity;
    }

    auto transform::set_parent(dude::transform *parent) -> void {
        _parent = parent;
    }

    auto transform::get_parent() -> dude::transform * {
        return _parent;
    }

    auto transform::get_parent() const -> dude::transform const * {
        return _parent;
    }

}