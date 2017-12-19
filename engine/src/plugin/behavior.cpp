//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/plugin/behavior.hpp>

namespace dude {

    behavior::~behavior() { // NOLINT

    }

    auto behavior::get_entity() const -> entity * {
        return nullptr;
    }

    auto behavior::set_entity(dude::entity *entity) -> void {

    }

    auto behavior::on_start() -> void {

    }

    auto behavior::on_resume() -> void {

    }

    auto behavior::on_update() -> void {

    }

    auto behavior::on_pause() -> void {

    }

    auto behavior::on_stop() -> void {

    }

}