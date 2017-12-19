//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <memory>
#include <vector>

#include <dude/entity/entity.hpp>

namespace dude { class engine; }

namespace dude {

    class scene final {
    public:
        using entity_t = std::unique_ptr<entity>;
        using entities_t = std::vector<entity_t>;

    public:
        scene() = default;
        ~scene() noexcept = default;

    public:
        scene(scene const &) = delete;
        scene(scene &&) = delete;
        auto operator=(scene const &) -> scene & = delete;
        auto operator=(scene &&) noexcept -> scene & = delete;

    public:
        auto get_engine() const -> engine *;
        auto set_engine(dude::engine *engine) -> void;

    public:
        auto get_entities() const -> entities_t const &;
    };

}