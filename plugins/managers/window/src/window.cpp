//
// Created by Jonathan Picques on 01/11/2016.
//

#include <window/window.hpp>

namespace dude {

    window::window() = default;

    window::~window() = default;

    auto window::on_start() -> void {
        _window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 320, 240, SDL_WINDOW_OPENGL);
        _renderer = SDL_CreateRenderer(_window, -1, 0);
    }

    auto window::on_update() -> void {
        SDL_RenderClear(_renderer);
    }

    auto window::on_stop() -> void {
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