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
        using engine_t = engine *;
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

    private:
        engine_t _engine;
        name_t _name;
    };

}