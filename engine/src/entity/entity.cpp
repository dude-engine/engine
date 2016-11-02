//
// Created by Jonathan Picques on 31/10/2016.
//

#include <cassert>

#include <dude/entity/entity.hpp>

namespace dude {

    auto entity::name(name_t const &name) -> void {
        assert(_name.empty());
        _name = name;
    }

    auto entity::name() const -> name_t const & {
        assert(!_name.empty());
        return _name;
    }

    auto entity::behaviors() const -> const entity::behaviors_t & {
        return _behaviors;
    }

    auto entity::has_behavior(std::string const &) const -> bool {
        return false;
    }

    auto entity::add_behavior(std::string const &, std::unique_ptr<behavior> &&) -> void {

    }

    auto entity::remove_behavior(std::string const &) -> void {

    }

    auto entity::enable(bool enable) -> void {

    }

    auto entity::enabled() const -> bool {
        return _enabled;
    }

}