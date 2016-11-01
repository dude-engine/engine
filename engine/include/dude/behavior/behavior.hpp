//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <dude/system.hpp>

namespace dude {

    class DUDE_API behavior {
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
        virtual auto on_destroy() -> void;
        virtual auto on_disable() -> void;

    public:
        auto configure_dependencies() -> void;
        auto configure_properties() -> void;

    public:
        auto enable(bool enable) -> void;
        auto enabled() const -> bool;

    private:
        bool _enabled;
    };

}