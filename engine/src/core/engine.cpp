//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/core/engine.hpp>

namespace dude {

    engine::engine() : _scene(std::make_unique<dude::scene>()) {

    }

    auto engine::start() -> void {

    }

    auto engine::pause() -> void {

    }

    auto engine::resume() -> void {

    }

    auto engine::stop() -> void {

    }

    auto engine::get_scene() const -> dude::scene * {
        return _scene.get();
    }

    auto engine::load_scene(std::string const &) -> dude::scene * {
        return nullptr;
    }

    auto engine::get_managers() const -> const managers_t & {
        return _managers;
    }

    auto engine::get_manager(std::string const &manager_name) -> dude::manager * {
        return nullptr;
    }

    auto engine::get_manager(std::string const &manager_name) const -> dude::manager const * {
        return nullptr;
    }

    auto engine::has_manager(std::string const &manager_name) const -> bool {
        return false;
    }

    auto engine::add_manager(std::string const &manager_name) -> dude::manager * {
        return nullptr;
    }

    auto engine::remove_manager(std::string const &manager_name) -> void {

    }

    auto engine::get_plugin_factory() const -> const engine::plugin_factory_t & {
        return _plugin_factory;
    }

    auto engine::get_plugin_factory() -> engine::plugin_factory_t & {
        return _plugin_factory;
    }

}