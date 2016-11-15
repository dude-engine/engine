//
// Created by Jonathan Picques on 01/11/2016.
//

#include <window/window.hpp>

namespace dude {

    window::window() = default;

    window::~window() = default;

    void window::on_start() {
        _window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 320, 240, SDL_WINDOW_OPENGL);
        _renderer = SDL_CreateRenderer(_window, -1, 0);
    }

    void window::on_update() {
        SDL_RenderClear(_renderer);
        SDL_Event e;
        while (SDL_PollEvent(&e) == 1) {
            if (e.type == SDL_QUIT) {
                // get_engine()->stop();
            }
        }
    }

    void window::on_stop() {
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyWindow(_window);
    }

}

extern "C" {
DUDE_API auto create_manager() -> dude::manager *;
DUDE_API auto create_manager() -> dude::manager * {
    return new dude::window();
}
}