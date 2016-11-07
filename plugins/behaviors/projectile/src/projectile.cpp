//
// Created by Jonathan Picques on 01/11/2016.
//

#include <iostream>

#include <projectile/projectile.hpp>

namespace dude {

    auto projectile::on_properties() const -> properties_t {
        return {
                {"speed", 10}
        };
    }

    auto projectile::on_create() -> void {
        std::cout << "dude::projectile::on_create()" << std::endl;
    }

    auto projectile::on_destroy() -> void {
        std::cout << "dude::projectile::on_destroy()" << std::endl;
    }

}

extern "C" {
    DUDE_API auto create_behavior() -> dude::behavior *;
    DUDE_API auto create_behavior() -> dude::behavior * {
        return new dude::projectile();
    }
}