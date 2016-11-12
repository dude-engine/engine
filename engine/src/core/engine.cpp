//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/core/engine.hpp>
#include <dude/utility/find.hpp>

namespace dude {

    engine::engine() : _scene(std::make_unique<dude::scene>()) {

    }

    auto engine::run() -> void {
        _stopped = false;
        while (!_stopped) {
            _timer.tick();
            for (auto it = _managers.begin(); it != _managers.end(); ++it) {
                (*it)->on_update();
            }
        }
        for (auto it = _managers.begin(); it != _managers.end(); ++it) {
            (*it)->on_stop();
        }
    }

    auto engine::pause() -> void {
        _paused = true;
        // TODO: call plugins on_pause
    }

    auto engine::resume() -> void {
        _paused = false;
        // TODO: call plugins on_resume
    }

    auto engine::stop() -> void {
        _stopped = true;
    }

    auto engine::get_timer() const -> timer_t const & {
        return _timer;
    }

    auto engine::get_scene() const -> dude::scene * {
        return _scene.get();
    }

    auto engine::load_scene(std::string const &) -> dude::scene * {
        return nullptr;
    }

    auto engine::get_managers() const -> const managers_t & {
        return _managers;
    }

    auto engine::get_manager(std::string const &manager_name) -> dude::manager * {
        auto manager_iterator = dude::find_by_name(_managers, manager_name);
        assert(manager_iterator != _managers.end());
        return (*manager_iterator).get();
    }

    auto engine::get_manager(std::string const &manager_name) const -> dude::manager const * {
        auto manager_iterator = dude::find_by_name(_managers, manager_name);
        assert(manager_iterator != _managers.end());
        return (*manager_iterator).get();
    }

    auto engine::has_manager(std::string const &manager_name) const -> bool {
        return dude::find_by_name(_managers, manager_name) != _managers.end();
    }

    auto engine::add_manager(std::string const &manager_name) -> dude::manager * {
        assert(!has_manager(manager_name));
        auto manager_ptr = std::move(_plugin_factory.make_manager(manager_name));
        auto manager = manager_ptr.get();
        manager->set_engine(this);
        manager->configure_dependencies();
        // TODO: resolve dependencies if any
        manager->configure_properties();
        manager->on_start();
        _managers.emplace_back(std::move(manager_ptr));
        // TODO: iterators invalidated
        return manager;
    }

    auto engine::remove_manager(std::string const &manager_name) -> void {
        auto manager_iterator = dude::find_by_name(_managers, manager_name);
        assert(manager_iterator != _managers.end());
        auto const &manager_ptr = *manager_iterator;
        auto manager = manager_ptr.get();
        manager->on_stop();
        _managers.erase(manager_iterator);
        // TODO: iterators invalidated
    }

    auto engine::get_plugin_factory() const -> const engine::plugin_factory_t & {
        return _plugin_factory;
    }

    auto engine::get_plugin_factory() -> engine::plugin_factory_t & {
        return _plugin_factory;
    }

}