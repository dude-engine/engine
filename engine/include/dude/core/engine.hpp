//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <memory>
#include <vector>

#include <dude/core/scene.hpp>
#include <dude/plugin/manager.hpp>

namespace dude {

    class engine final {
    public:
        using scene_t = std::unique_ptr<scene>;
        using manager_t = std::unique_ptr<manager>;
        using managers_t = std::vector<manager_t>;

    public:
        engine() = default;
        ~engine() noexcept = default;

    public:
        engine(engine const &) = delete;
        engine(engine &&) = delete;
        auto operator=(engine const &) -> engine & = delete;
        auto operator=(engine &&) noexcept -> engine & = delete;

    public:
        auto start() -> void;
        auto resume() -> void;
        auto run() -> void;
        auto pause() -> void;
        auto stop() -> void;

    public:
        auto get_scene() const -> scene *;
        auto get_managers() const -> managers_t const &;
    };

}