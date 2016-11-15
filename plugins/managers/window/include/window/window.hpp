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
        virtual void on_start() override final;
        virtual void on_update() override final;
        virtual void on_stop() override final;

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
    };

}