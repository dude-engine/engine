//
// Created by Jonathan Picques on 03/11/2016.
//

#pragma once

#include <string>
#include <unordered_map>

#include <dude/system.hpp>
#include <dude/property/property.hpp>

namespace dude { class engine; }

namespace dude {

    class DUDE_API plugin {
    public:
        using name_t = std::string;
        using enabled_t = bool;
        using property_t = dude::property;
        using properties_t = std::unordered_map<std::string, property>;

    public:
        plugin() = default;
        virtual ~plugin() = default;

    private:
        plugin(plugin const &) = delete;
        plugin(plugin &&) = delete;
        auto operator=(plugin const &) -> void = delete;

    public:
        virtual auto on_properties() const -> properties_t;
        virtual auto on_enable() -> void;
        virtual auto on_disable() -> void;

    public:
        auto get_name() const -> name_t const &;
        auto set_name(name_t const &) -> void;

    public:
        auto get_engine() const -> dude::engine *;
        auto set_engine(dude::engine *engine) -> void;

    public:
        auto get_properties() const -> properties_t const &;
        auto get_property(std::string const &property_name) const -> property_t const &;
        auto get_property(std::string const &property_name) -> property_t &;

    public:
        auto is_enabled() const -> enabled_t const &;
        auto set_enabled(enabled_t const &enable) -> void;

    public:
        auto configure_properties() -> void;

    private:
        name_t _name;
        dude::engine *_engine;
        enabled_t _enabled = true;
        properties_t _properties;
    };

}