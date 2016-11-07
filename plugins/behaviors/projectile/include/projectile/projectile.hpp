//
// Created by Jonathan Picques on 01/11/2016.
//

#pragma once

#include <dude/plugin/behavior.hpp>

namespace dude {

    class projectile final : public behavior {
    public:
        projectile() = default;
        virtual ~projectile() = default;

    public:
        virtual auto on_properties() const -> properties_t override final;

    public:
        virtual auto on_create() -> void override final;
        virtual auto on_destroy() -> void override final;
    };

}