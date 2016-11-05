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

    auto engine::scene() const -> scene_t {
        return _scene;
    }

    auto engine::load_scene(std::string const &) -> scene_t {
        return nullptr;
    }

    auto engine::managers() const -> const managers_t & {
        return _managers;
    }

    auto engine::has_manager(std::string const &manager_name) const -> bool {
        return false;
    }

    auto engine::add_manager(std::string const &manager_name, std::unique_ptr<manager> &&add_manager) -> void {

    }

    auto engine::remove_manager(std::string const &manager_name) -> void {

    }

}