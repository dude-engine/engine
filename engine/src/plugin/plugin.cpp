//
// Created by Jonathan Picques on 03/11/2016.
//

#include <dude/plugin/plugin.hpp>

namespace dude {

    auto plugin::engine() const -> engine_t {
        return _engine;
    }

    auto plugin::engine(engine_t engine) -> void {

    }

    auto plugin::name(name_t const &name) -> void {

    }

    auto plugin::name() const -> name_t const & {
        return _name;
    }

    auto plugin::enable(enabled_t const &enable) -> void {

    }

    auto plugin::enabled() const -> enabled_t const & {
        return _enabled;
    }
}