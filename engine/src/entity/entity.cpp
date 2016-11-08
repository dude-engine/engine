//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/entity/entity.hpp>

namespace dude {

    auto entity::scene() const -> dude::scene * {
        return _scene;
    }

    auto entity::scene(dude::scene *scene) -> void {

    }

    auto entity::parent() const -> dude::entity * {
        return _parent;
    }

    auto entity::parent(dude::entity *parent) -> void {

    }

    auto entity::name() const -> name_t const & {
        return _name;
    }

    auto entity::name(name_t const &name) -> void {

    }

    auto entity::entities() const -> const entities_t & {
        return _entities;
    }

    auto entity::has_entity(std::string const &entity_name) const -> bool {
        return false;
    }

    auto entity::add_entity(std::string const &entity_name, std::unique_ptr<entity> &&add_entity) -> void {

    }

    auto entity::remove_entity(std::string const &entity_name) -> void {

    }

    auto entity::behaviors() const -> const entity::behaviors_t & {
        return _behaviors;
    }

    auto entity::has_behavior(std::string const &behavior_name) const -> bool {
        return false;
    }

    auto entity::add_behavior(std::string const &behavior_name, std::unique_ptr<behavior> &&add_behavior) -> void {

    }

    auto entity::remove_behavior(std::string const &behavior_name) -> void {

    }

    auto entity::enabled() const -> bool {
        return _enabled;
    }

    auto entity::enable(bool enable) -> void {

    }

}