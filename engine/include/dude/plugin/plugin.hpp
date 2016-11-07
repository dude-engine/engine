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
        using engine_t = dude::engine *;
        using enabled_t = bool;
        using property_t = dude::property;
        using properties_t = std::unordered_map<std::string, property>;

    public:
        plugin() = default;
        virtual ~plugin() = default;

    private:
        plugin(plugin const &) = delete;
        plugin(plugin &&) = delete;
        void operator=(plugin const &) = delete;

    public:
        virtual auto on_create() -> void;
        virtual auto on_destroy() -> void;
        virtual auto on_properties() const -> properties_t;

    public:
        auto name() const -> name_t const &;
        auto name(name_t const &) -> void;

    public:
        auto engine() const -> engine_t;
        auto engine(engine_t engine) -> void;

    public:
        auto properties() const -> properties_t const &;
        auto property(std::string const &property_name) const -> property_t const &;
        auto property(std::string const &property_name) -> property_t &;

    public:
        auto enabled() const -> enabled_t const &;
        auto enable(enabled_t const &enable) -> void;

    public:
        auto configure_properties() -> void;

    private:
        name_t _name;
        engine_t _engine;
        enabled_t _enabled;
        properties_t _properties;
    };

}