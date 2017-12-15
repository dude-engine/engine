//
// Created by Jonathan Picques on 03/11/2016.
//

#include <dude/plugin/plugin.hpp>

namespace dude {

    plugin::~plugin() { // NOLINT

    }

    auto plugin::on_enable() -> void {

    }

    auto plugin::on_disable() -> void {

    }

    auto plugin::on_properties() const -> properties_t {
        return properties_t();
    }

    auto plugin::get_engine() const -> dude::engine* {
        return _engine;
    }

    auto plugin::set_engine(dude::engine* engine) -> void {
        _engine = engine;
    }

    auto plugin::get_name() const -> name_t const & {
        return _name;
    }

    auto plugin::set_name(name_t const &name) -> void {
        _name = name;
    }

    auto plugin::get_properties() const -> const plugin::properties_t & {
        return _properties;
    }

    auto plugin::get_property(std::string const &property_name) const -> const plugin::property_t & {
        return _properties.at(property_name);
    }

    auto plugin::get_property(const std::string &property_name) -> property_t & {
        return _properties.at(property_name);
    }

    auto plugin::is_enabled() const -> enabled_t const & {
        return _enabled;
    }

    auto plugin::set_enabled(enabled_t const &enable) -> void {

    }

    auto plugin::configure_properties() -> void {
        _properties = on_properties();
    }

}