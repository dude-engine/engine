//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <dude/system.hpp>
#include <dude/plugin/plugin.hpp>

namespace dude {

    class DUDE_API behavior : public plugin {
    public:
        using enabled_t = bool;

    public:
        behavior() = default;
        virtual ~behavior() = default;

    public:
        virtual auto on_dependencies() -> void;
        virtual auto on_properties() -> void;

    public:
        virtual auto on_enable() -> void;
        virtual auto on_start() -> void;
        virtual auto on_update() -> void;
        virtual auto on_stop() -> void;
        virtual auto on_disable() -> void;

    public:
        auto configure_dependencies() -> void;
        auto configure_properties() -> void;

    public:
        auto enable(enabled_t const &enable) -> void;
        auto enabled() const -> enabled_t const &;

    private:
        enabled_t _enabled;
    };

}