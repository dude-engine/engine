//
// Created by Jonathan Picques on 01/11/2016.
//

#pragma once

#include <dude/plugin/behavior.hpp>

namespace dude {

    class projectile final : public dude::behavior {
    public:
        projectile();
        ~projectile() override;

    public:
        auto on_properties() const -> properties_t final;
    };

}