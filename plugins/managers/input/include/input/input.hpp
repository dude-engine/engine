//
// Created by Jonathan Picques on 01/11/2016.
//

#pragma once

#include <SDL2/SDL.h>

#include <dude/plugin/manager.hpp>

namespace dude {

    class input final : public manager {
    public:
        input() = default;
        virtual ~input() = default;

    public:
        virtual auto on_update() -> void override final;

    private:
        SDL_Event _event;
    };

}