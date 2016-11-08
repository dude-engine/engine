#include <dude/core/engine.hpp>

int main() {
    dude::engine engine;
    auto renderer = engine.add_manager("renderer");
    auto input = engine.add_manager("input");
    auto player = engine.scene()->add_entity("player");
    auto hat = player->add_child("hat");
    auto platformer = player->add_behavior("platformer");
    auto sprite = hat->add_behavior("sprite");
    return 0;
}