//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/core/engine.hpp>

namespace dude {

    auto engine::start() -> void {

    }

    auto engine::pause() -> void {

    }

    auto engine::resume() -> void {

    }

    auto engine::stop() -> void {

    }

    auto engine::scene() const -> dude::scene * {
        return _scene.get();
    }

    auto engine::load_scene(std::string const &) -> dude::scene * {
        return nullptr;
    }

    auto engine::managers() const -> const managers_t & {
        return _managers;
    }

    auto engine::manager(std::string const &manager_name) -> dude::manager * {
        return nullptr;
    }

    auto engine::manager(std::string const &manager_name) const -> dude::manager const * {
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

    auto engine::plugin_factory() const -> const engine::plugin_factory_t & {
        return _plugin_factory;
    }

    auto engine::plugin_factory() -> engine::plugin_factory_t & {
        return _plugin_factory;
    }

}