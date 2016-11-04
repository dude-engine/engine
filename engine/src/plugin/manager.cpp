//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/plugin/manager.hpp>

namespace dude {

    auto manager::on_manager_dependencies() -> dependencies_t {
        return dependencies_t();
    }

    auto manager::on_dependencies() -> dependencies_t {
        return dependencies_t();
    }

    auto manager::on_enable() -> void {

    }

    auto manager::on_start() -> void {

    }

    auto manager::on_update() -> void {

    }

    auto manager::on_stop() -> void {

    }

    auto manager::on_disable() -> void {

    }

    auto manager::manager_dependencies() const -> const dependencies_t & {
        return _manager_dependencies;
    }

    auto manager::dependencies() const -> const dependencies_t & {
        return _dependencies;
    }

    auto manager::configure_manager_dependencies() -> void {

    }

    auto manager::configure_dependencies() -> void {

    }

}