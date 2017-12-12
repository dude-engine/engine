//
// Created by Jonathan Picques on 12-Dec-17.
// Copyright (c) 2017 Jonathan Picques. All rights reserved.
//

#pragma once

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>

namespace gravity { class entity; }

namespace gravity {

    class transform final {
    public:
        transform() = default;
        ~transform() = default;

    public:
        transform(transform const &) = delete;
        transform(transform &&) = delete;
        auto operator=(transform const &) -> void = delete;

    private:
        entity *_entity = nullptr;
        transform *_parent = nullptr;

    private:
        glm::vec3 _scale = {};
        glm::vec3 _position = {};
        glm::quat _rotation = {};
    };

}