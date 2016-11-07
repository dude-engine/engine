//
// Created by Jonathan Picques on 01/11/2016.
//

#pragma once

#include <dude/plugin/manager.hpp>

namespace dude {

    class input final : public manager {
    public:
        input() = default;
        virtual ~input() = default;

    public:
        virtual auto on_create() -> void override final;
        virtual auto on_destroy() -> void override final;
    };

}