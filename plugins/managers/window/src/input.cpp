//
// Created by Jonathan Picques on 01/11/2016.
//

#include <iostream>

#include <input/input.hpp>

namespace dude {

    input::input() {
        std::cout << "input::input()" << std::endl;
    }

    input::~input() {
        std::cout << "input::~input()" << std::endl;
    }

}

extern "C" {
    DUDE_API auto create_manager() -> dude::manager *;
    DUDE_API auto create_manager() -> dude::manager * {
        return new dude::input();
    }
}