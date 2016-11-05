//
// Created by Jonathan Picques on 03/11/2016.
//

#include <dude/plugin/plugin.hpp>

namespace dude {

    auto plugin::on_create() -> void {

    }

    auto plugin::on_destroy() -> void {

    }

    auto plugin::on_properties() const -> properties_t {
        return properties_t();
    }

    auto plugin::engine() const -> engine_t {
        return _engine;
    }

    auto plugin::engine(engine_t engine) -> void {
        _engine = engine;
    }

    auto plugin::name() const -> name_t const & {
        return _name;
    }

    auto plugin::name(name_t const &name) -> void {
        _name = name;
    }

    auto plugin::properties() const -> const plugin::properties_t & {
        return _properties;
    }

    auto plugin::properties(const plugin::properties_t &) -> void {

    }

    auto plugin::enabled() const -> enabled_t const & {
        return _enabled;
    }

    auto plugin::enable(enabled_t const &enable) -> void {

    }

    auto plugin::configure_properties() -> void {

    }

}