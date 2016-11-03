//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <memory>
#include <vector>

#include <dude/plugin/manager.hpp>

namespace dude { class scene; }

namespace dude {

    class engine final {
    public:
        using scene_t = dude::scene *;
        using managers_t = std::vector<std::unique_ptr<manager>>;

    public:
        engine() = default;
        ~engine() = default;

    public:
        auto start() -> void;
        auto pause() -> void;
        auto resume() -> void;
        auto stop() -> void;

    public:
        auto scene() const -> scene_t;
        auto load_scene(std::string const &) -> scene_t;

    public:
        auto managers() const -> managers_t const &;
        auto has_manager(std::string const &) const -> bool;
        auto add_manager(std::string const &, std::unique_ptr<manager> &&) -> void;
        auto remove_manager(std::string const &) -> void;

    private:
        scene_t _scene;
        managers_t _managers;
    };

}