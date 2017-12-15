//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/plugin/behavior.hpp>

namespace dude {

    behavior::~behavior() { // NOLINT

    }

    auto behavior::on_manager_dependencies() -> dependencies_t {
        return dependencies_t();
    }

    auto behavior::on_dependencies() -> dependencies_t {
        return dependencies_t();
    }

    auto behavior::on_start() -> void {

    }

    auto behavior::on_update() -> void {

    }

    auto behavior::on_stop() -> void {

    }

    auto behavior::get_entity() const -> dude::entity * {
        return _entity;
    }

    auto behavior::set_entity(dude::entity *entity) -> void {
        _entity = entity;
    }

    auto behavior::get_manager_dependencies() const -> const dependencies_t & {
        return _manager_dependencies;
    }

    auto behavior::get_dependencies() const -> const dependencies_t & {
        return _dependencies;
    }

    auto behavior::configure_manager_dependencies() -> void {

    }

    auto behavior::configure_dependencies() -> void {

    }

}