//
// Created by Jonathan Picques on 31/10/2016.
//

#include <string>
#include <iostream>

#include <dude/core/engine.hpp>
#include <dude/plugin/manager.hpp>
#include <dude/serialization/json_saver.hpp>

class gameplay : public dude::manager {
public:
    virtual properties_t on_properties() const override {
        return {
                {"lives", 5},
                {"hp",    2}
        };
    }

    virtual void on_start() override {
        get_engine()->add_manager("platform");
    }

    virtual void on_update() override {
        if (!_removed && get_engine()->get_timer().elapsed() > 0.5) {
            get_property("lives") = get_engine()->get_manager("platform")->get_property("speed").get<int>();
            get_engine()->remove_manager("platform");
            _removed = true;
        }
        if (get_engine()->get_timer().elapsed() > 1) {
            get_engine()->stop();
        }
    }

private:
    bool _removed = false;
};

class platform : public dude::manager {

    virtual properties_t on_properties() const override {
        return {
                {"speed",     42},
                {"direction", std::string{"right"}}
        };
    }

    virtual void on_update() override {
        get_property("speed") = get_property("speed").get<int>() + 1;
    }

public:
    virtual void on_stop() override {
        get_property("speed") = 0;
    }

};

int main() {
    dude::engine engine;
    engine.get_plugin_factory().register_manager<gameplay>("gameplay");
    engine.get_plugin_factory().register_manager<platform>("platform");
    engine.add_manager("gameplay");
    engine.run();
    std::cout << "game ran for " << engine.get_timer().elapsed() << " second(s)" << std::endl;
    std::cout << dude::json_saver().save(engine) << std::endl;
    return 0;
}