//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/plugin/behavior.hpp>

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

    auto behavior::on_stop() -> void {

    }

    auto behavior::on_disable() -> void {

    }

    auto behavior::configure_dependencies() -> void {

    }

    auto behavior::configure_properties() -> void {

    }

    auto behavior::enable(enabled_t const &enable) -> void {

    }

    auto behavior::enabled() const -> enabled_t const & {
        return _enabled;
    }
}