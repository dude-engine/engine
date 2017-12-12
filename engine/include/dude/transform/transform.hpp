//
// Created by Jonathan Picques on 12-Dec-17.
// Copyright (c) 2017 Jonathan Picques. All rights reserved.
//

#pragma once

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>

namespace dude { class entity; }

namespace dude {

    class transform final {
    public:
        transform() = default;
        ~transform() = default;

    public:
        transform(transform const &) = delete;
        transform(transform &&) = delete;
        auto operator=(transform const &) -> void = delete;

    public:
        auto set_entity(dude::entity *entity) -> void;
        auto get_entity() -> dude::entity *;
        auto get_entity() const -> dude::entity const *;

    public:
        auto set_parent(dude::transform *parent) -> void;
        auto get_parent() -> dude::transform *;
        auto get_parent() const -> dude::transform const *;

    private:
        dude::entity *_entity = nullptr;
        dude::transform *_parent = nullptr;

    private:
        glm::vec3 _scale = {};
        glm::vec3 _position = {};
        glm::quat _rotation = {};
    };

}