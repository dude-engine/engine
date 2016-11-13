//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <memory>
#include <vector>
#include <utility>

#include <dude/core/timer.hpp>
#include <dude/core/scene.hpp>
#include <dude/plugin/factory.hpp>
#include <dude/plugin/manager.hpp>

namespace dude { class scene; }

namespace dude {

    class engine final {
    public:
        using timer_t = dude::timer;
        using scene_t = std::unique_ptr<dude::scene>;
        using manager_t = std::unique_ptr<dude::manager>;
        using managers_t = std::vector<manager_t>;
        using managers_iterator_t = managers_t::const_iterator;
        using plugin_factory_t = dude::plugin_factory;

    public:
        engine();
        ~engine() = default;

    private:
        engine(engine const &) = delete;
        engine(engine &&) = delete;
        auto operator=(engine const &) -> void = delete;

    public:
        auto run() -> void;
        auto pause() -> void;
        auto resume() -> void;
        auto stop() -> void;

    public:
        auto get_timer() const -> timer_t const &;

    public:
        auto get_scene() const -> dude::scene *;
        auto load_scene(std::string const &scene_name) -> dude::scene *;

    public:
        auto get_managers() const -> managers_t const &;
        auto get_manager(std::string const &manager_name) -> dude::manager *;
        auto get_manager(std::string const &manager_name) const -> dude::manager const *;
        auto has_manager(std::string const &manager_name) const -> bool;
        auto add_manager(std::string const &manager_name) -> dude::manager *;
        auto remove_manager(std::string const &manager_name) -> void;

    public:
        auto get_plugin_factory() const -> plugin_factory_t const &;
        auto get_plugin_factory() -> plugin_factory_t &;

    private:
        timer_t _timer;
        scene_t _scene;
        managers_t _managers;
        plugin_factory_t _plugin_factory;
        managers_iterator_t _iterator;

    private:
        bool _stopped;
        bool _paused;
    };

}