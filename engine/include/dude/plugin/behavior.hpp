//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <string>
#include <unordered_set>

#include <dude/system.hpp>
#include <dude/plugin/plugin.hpp>

namespace dude { class entity; }

namespace dude {

    class DUDE_API behavior : public dude::plugin {
    public:
        behavior() = default;
        ~behavior() override = 0;

    public:
        behavior(behavior const &) = delete;
        behavior(behavior &&) = delete;
        auto operator=(behavior const &) -> void = delete;

    public:
        auto get_entity() const -> dude::entity *;
        auto set_entity(dude::entity *entity) -> void;

    public:
        virtual auto on_start() -> void;
        virtual auto on_resume() -> void;
        virtual auto on_update() -> void;
        virtual auto on_pause() -> void;
        virtual auto on_stop() -> void;
    };

}