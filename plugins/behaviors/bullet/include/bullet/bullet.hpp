//
// Created by Jonathan Picques on 01/11/2016.
//

#pragma once

#include <dude/plugin/behavior.hpp>

namespace dude {

    class bullet final : public behavior {
    public:
        bullet() = default;
        virtual ~bullet() = default;

    public:
        virtual auto on_create() -> void;
        virtual auto on_destroy() -> void;
    };

}