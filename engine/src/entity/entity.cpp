//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/entity/entity.hpp>

namespace dude {

    auto entity::get_scene() const -> dude::scene * {
        return _scene;
    }

    auto entity::set_scene(dude::scene *scene) -> void {

    }

    auto entity::get_parent() const -> dude::entity * {
        return _parent;
    }

    auto entity::set_parent(dude::entity *parent) -> void {

    }

    auto entity::get_name() const -> name_t const & {
        return _name;
    }

    auto entity::set_name(name_t const &name) -> void {

    }

    auto entity::get_child(std::string const &child_name) -> dude::entity * {
        return nullptr;
    }

    auto entity::get_child(std::string const &child_name) const -> dude::entity const * {
        return nullptr;
    }

    auto entity::get_children() const -> const entity::entities_t & {
        return _children;
    }

    auto entity::has_child(std::string const &child_name) const -> bool {
        return false;
    }

    auto entity::add_child(std::string const &child_name) -> dude::entity * {
        return nullptr;
    }

    auto entity::remove_child(std::string const &child_name) -> void {

    }

    auto entity::get_behaviors() const -> const entity::behaviors_t & {
        return _behaviors;
    }

    auto entity::get_behavior(std::string const &behavior_name) -> dude::behavior * {
        return nullptr;
    }

    auto entity::get_behavior(std::string const &behavior_name) const -> dude::behavior const * {
        return nullptr;
    }

    auto entity::has_behavior(std::string const &behavior_name) const -> bool {
        return false;
    }

    auto entity::add_behavior(std::string const &behavior_name) -> dude::behavior * {
        return nullptr;
    }

    auto entity::remove_behavior(std::string const &behavior_name) -> void {

    }

    auto entity::is_enabled() const -> bool {
        return _enabled;
    }

    auto entity::set_enabled(bool enable) -> void {

    }

}