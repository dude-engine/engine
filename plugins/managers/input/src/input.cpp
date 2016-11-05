//
// Created by Jonathan Picques on 01/11/2016.
//

#include <iostream>

#include <input/input.hpp>

namespace dude {

    auto input::on_create() -> void {
        std::cout << "dude::input::on_create()" << std::endl;
    }

    auto input::on_destroy() -> void {
        std::cout << "dude::input::on_destroy()" << std::endl;
    }
}

extern "C" {
    DUDE_API auto create_manager() -> dude::manager *;
    DUDE_API auto create_manager() -> dude::manager * {
        return new dude::input();
    }
}