//
// Created by Jonathan Picques on 12-Dec-17.
// Copyright (c) 2017 Jonathan Picques. All rights reserved.
//

#pragma once

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <dude/plugin/behavior.hpp>

namespace dude { class entity; }

namespace dude {

    class transform final : public dude::behavior {
    public:
        enum class coord_space { local, world };
    public:
        using scale_t = glm::vec3;
        using position_t = glm::vec3;
        using rotation_t = glm::quat;

    public:
        transform() = default;
        ~transform() final = default;

    public:
        transform(transform const &) = delete;
        transform(transform &&) = delete;
        auto operator=(transform const &) -> void = delete;

    public:
        auto set_parent(dude::transform *parent) -> void;
        auto get_parent() -> dude::transform *;
        auto get_parent() const -> dude::transform const *;

    public:
        auto get_scale(dude::transform::coord_space const &coord_space) const -> scale_t;
        auto get_position(dude::transform::coord_space const &coord_space) const -> position_t;
        auto get_rotation(dude::transform::coord_space const &coord_space) const -> rotation_t;

    private:
        dude::transform *_parent = nullptr;

    private:
        scale_t _scale = {};
        position_t _position = {};
        rotation_t _rotation = {};
    };

}