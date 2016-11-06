//
// Created by Jonathan Picques on 01/11/2016.
//

#include <iostream>

#include <bullet/bullet.hpp>

namespace dude {

    auto bullet::on_create() -> void {
        std::cout << "dude::bullet::on_create()" << std::endl;
    }

    auto bullet::on_destroy() -> void {
        std::cout << "dude::bullet::on_destroy()" << std::endl;
    }
}

extern "C" {
    DUDE_API auto create_behavior() -> dude::behavior *;
    DUDE_API auto create_behavior() -> dude::behavior * {
        return new dude::bullet();
    }
}