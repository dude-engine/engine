//
// Created by Jonathan Picques on 01/11/2016.
//

#pragma once

#include <dude/plugin/behavior.hpp>

namespace dude {

    class projectile final : public behavior {
    public:
        projectile();
        ~projectile() noexcept override;

    public:
        auto on_properties() const -> properties_t final;
    };

}