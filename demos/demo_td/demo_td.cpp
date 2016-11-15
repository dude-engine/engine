//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/core/engine.hpp>
#include <dude/plugin/manager.hpp>

class gameplay : public dude::manager {
public:
    virtual void on_update() override {
        if (get_engine()->get_timer().elapsed() > 1) get_engine()->stop();
    }
};

int main() {
    dude::engine engine;
    engine.get_plugin_factory().register_manager("window", "plugins/managers/window/libmanager_window");
    engine.get_plugin_factory().register_manager("input", "plugins/managers/input/libmanager_input");
    engine.get_plugin_factory().register_manager<gameplay>("gameplay");
    engine.add_manager("window");
    engine.add_manager("gameplay");
    engine.run();
    return 0;
}