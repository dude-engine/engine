//
// Created by Jonathan Picques on 01/11/2016.
//

#include <iostream>

#include <projectile/projectile.hpp>

namespace dude {

    projectile::projectile() {
        std::cout << "projectile::projectile()" << std::endl;
    }

    projectile::~projectile() {
        std::cout << "projectile::~projectile()" << std::endl;
    }

    auto projectile::on_properties() const -> properties_t {
        return {
                {"speed", 10}
        };
    }

}

extern "C" {
    DUDE_API auto create_behavior() -> dude::behavior *;
    DUDE_API auto create_behavior() -> dude::behavior * {
        return new dude::projectile();
    }
}