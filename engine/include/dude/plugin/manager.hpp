//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <string>
#include <unordered_set>

#include <dude/system.hpp>
#include <dude/plugin/plugin.hpp>

namespace dude { class engine; }

namespace dude {

    class DUDE_API manager : public plugin {

    public:
        manager() = default;
        ~manager() noexcept override = 0;

    public:
        manager(manager const &) = delete;
        manager(manager &&) = delete;
        auto operator=(manager const &) -> manager & = delete;
        auto operator=(manager &&) noexcept -> manager & = delete;

    public:
        auto get_engine() const -> engine *;
        auto set_engine(dude::engine *engine) -> void;

    public:
        virtual auto on_start() -> void;
        virtual auto on_resume() -> void;
        virtual auto on_update() -> void;
        virtual auto on_pause() -> void;
        virtual auto on_stop() -> void;
    };

}