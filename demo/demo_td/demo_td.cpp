#include <memory>

#include <dude/core/library.hpp>
#include <dude/behavior/behavior.hpp>

int main() {
    auto library = dude::library("../../plugins/input/libplugin_input");
    auto behavior_creator = library.symbol<dude::behavior *(*)()>("create");
    auto behavior = std::unique_ptr<dude::behavior>(behavior_creator());
    behavior->enable(false);
    return 0;
}
