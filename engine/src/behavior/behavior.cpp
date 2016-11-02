//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/behavior/behavior.hpp>

namespace dude {

    auto behavior::on_dependencies() -> void {

    }

    auto behavior::on_properties() -> void {

    }

    auto behavior::on_enable() -> void {

    }

    auto behavior::on_start() -> void {

    }

    auto behavior::on_update() -> void {

    }

    auto behavior::on_destroy() -> void {

    }

    auto behavior::on_disable() -> void {

    }

    auto behavior::configure_dependencies() -> void {

    }

    auto behavior::configure_properties() -> void {

    }

    auto behavior::name(name_t const &name) -> void {

    }

    auto behavior::name() const -> name_t const & {
        return _name;
    }

    auto behavior::enable(enabled_t const &enable) -> void {

    }

    auto behavior::enabled() const -> enabled_t const & {
        return _enabled;
    }
}