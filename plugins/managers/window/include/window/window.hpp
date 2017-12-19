//
// Created by Jonathan Picques on 01/11/2016.
//

#pragma once

#include <SDL2/SDL.h>

#include <dude/plugin/manager.hpp>

namespace dude {

    class window final : public dude::manager {
    public:
        window() = default;
        ~window() override = default;

    public:
        auto on_start() -> void final;
        auto on_update() -> void final;
        auto on_stop() -> void final;

    private:
        SDL_Window *_window = nullptr;
        SDL_Renderer *_renderer = nullptr;
    };

}