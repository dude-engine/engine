//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <memory>
#include <vector>

#include <dude/plugin/behavior.hpp>

namespace dude { class scene; }

namespace dude {

    class entity final {
    public:
        using behavior_t = std::unique_ptr<behavior>;
        using behaviors_t = std::vector<behavior_t>;

    public:
        entity() = default;
        ~entity() = default;

    public:
        entity(entity const &) = delete;
        entity(entity &&) = delete;
        auto operator=(entity const &) -> entity & = delete;

    public:
        auto get_scene() const -> dude::scene *;
        auto set_scene(dude::scene *scene) -> void;

    public:
        auto get_behaviors() const -> behaviors_t const &;

    public:
        auto start() -> void;
        auto resume() -> void;
        auto update() -> void;
        auto pause() -> void;
        auto stop() -> void;
    };

}