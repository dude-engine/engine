//
// Created by Jonathan Picques on 01/11/2016.
//

#pragma once

#include <SDL2/SDL.h>

#include <dude/plugin/manager.hpp>

namespace dude {

    class input final : public dude::manager {
    public:
        input() = default;
        ~input() override = default;

    public:
        auto on_update() -> void final;

    private:
        SDL_Event _event;
    };

}