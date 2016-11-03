//
// Created by Jonathan Picques on 03/11/2016.
//

#pragma once

#include <string>

#include <dude/system.hpp>

namespace dude { class engine; }

namespace dude {

    class DUDE_API plugin {
    public:
        using engine_t = dude::engine *;
        using enabled_t = bool;
        using name_t = std::string;

    public:
        virtual auto on_create() -> void {}
        virtual auto on_destroy() -> void {}

    public:
        auto engine() const -> engine_t;
        auto engine(engine_t engine) -> void;

    public:
        auto name(name_t const &) -> void;
        auto name() const -> name_t const &;

    public:
        auto enable(enabled_t const &enable) -> void;
        auto enabled() const -> enabled_t const &;

    private:
        engine_t _engine;
        enabled_t _enabled;
        name_t _name;
    };

}