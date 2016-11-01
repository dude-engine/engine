//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <memory>
#include <vector>

namespace dude { class behavior; }

namespace dude {

    class entity {
    public:
        using behaviors_t = std::vector<std::unique_ptr<behavior>>;

    public:
        entity() = default;
        ~entity() = default;

    public:
        auto behaviors() const -> behaviors_t const &;
        auto has_behavior(std::string const &) const -> bool;
        auto add_behavior(std::string const &, std::unique_ptr<behavior> &&) -> void;
        auto remove_behavior(std::string const &) -> void;

    public:
        auto enable(bool enable) -> void;
        auto enabled() const -> bool;

    private:
        bool _enabled;
        behaviors_t _behaviors;
    };

}