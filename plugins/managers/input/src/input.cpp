//
// Created by Jonathan Picques on 01/11/2016.
//

#include <iostream>

#include <SDL2/SDL.h>

#include <dude/core/engine.hpp>
#include <input/input.hpp>

namespace dude {

    auto input::on_update() -> void {
        while(SDL_PollEvent(&_event) == 1) {
            if (_event.type == SDL_KEYDOWN) {
                std::cout << _event.key.keysym.scancode << std::endl;
            } else if (_event.type == SDL_QUIT) {
                // get_engine()->stop();
            }
        }
    }

}

extern "C" {
    DUDE_API auto create_manager() -> dude::manager *;
    DUDE_API auto create_manager() -> dude::manager * {
        return new dude::input();
    }
}