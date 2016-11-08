//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <memory>
#include <vector>

#include <dude/core/scene.hpp>
#include <dude/plugin/factory.hpp>
#include <dude/plugin/manager.hpp>

namespace dude { class scene; }

namespace dude {

    class engine final {
    public:
        using scene_t = std::unique_ptr<dude::scene>;
        using managers_t = std::vector<std::unique_ptr<dude::manager>>;
        using plugin_factory_t = dude::plugin_factory;

    public:
        engine() = default;
        ~engine() = default;

    private:
        engine(engine const &) = delete;
        engine(engine &&) = delete;
        void operator=(engine const &) = delete;

    public:
        auto start() -> void;
        auto pause() -> void;
        auto resume() -> void;
        auto stop() -> void;

    public:
        auto scene() const -> dude::scene *;
        auto load_scene(std::string const &scene_name) -> dude::scene *;

    public:
        auto managers() const -> managers_t const &;
        auto manager(std::string const &manager_name) -> dude::manager *;
        auto manager(std::string const &manager_name) const -> dude::manager const *;
        auto has_manager(std::string const &manager_name) const -> bool;
        auto add_manager(std::string const &manager_name) -> dude::manager *;
        auto remove_manager(std::string const &manager_name) -> void;

    public:
        auto plugin_factory() const -> plugin_factory_t const &;
        auto plugin_factory() -> plugin_factory_t &;

    private:
        scene_t _scene;
        managers_t _managers;
        plugin_factory_t _plugin_factory;
    };

}