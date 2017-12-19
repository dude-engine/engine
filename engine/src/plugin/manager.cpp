//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/plugin/manager.hpp>

namespace dude {

    manager::~manager() { // NOLINT

    }

    auto manager::get_engine() const -> engine * {
        return nullptr;
    }

    auto manager::set_engine(dude::engine *engine) -> void {

    }

    auto manager::on_start() -> void {

    }

    auto manager::on_resume() -> void {

    }

    auto manager::on_update() -> void {

    }

    auto manager::on_pause() -> void {

    }

    auto manager::on_stop() -> void {

    }

}