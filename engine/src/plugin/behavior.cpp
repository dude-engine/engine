//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/plugin/behavior.hpp>

namespace dude {

    auto behavior::on_manager_dependencies() -> dependencies_t {
        return dependencies_t();
    }

    auto behavior::on_dependencies() -> dependencies_t {
        return dependencies_t();
    }

    auto behavior::on_enable() -> void {

    }

    auto behavior::on_start() -> void {

    }

    auto behavior::on_update() -> void {

    }

    auto behavior::on_stop() -> void {

    }

    auto behavior::on_disable() -> void {

    }

    auto behavior::entity() const -> behavior::entity_t {
        return _entity;
    }

    auto behavior::entity(behavior::entity_t entity) -> void {

    }

    auto behavior::manager_dependencies() const -> const dependencies_t & {
        return _manager_dependencies;
    }

    auto behavior::dependencies() const -> const dependencies_t & {
        return _dependencies;
    }

    auto behavior::configure_manager_dependencies() -> void {

    }

    auto behavior::configure_dependencies() -> void {

    }

}