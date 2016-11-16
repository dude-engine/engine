//
// Created by Jonathan Picques on 01/11/2016.
//

#pragma once

#include <SDL.h>

#include <dude/plugin/manager.hpp>

namespace dude {

    class window final : public manager {
    public:
        window();
        virtual ~window();

    public:
        virtual auto on_start() -> void override final;
        virtual auto on_update() -> void override final;
        virtual auto on_stop() -> void override final;

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
    };

}