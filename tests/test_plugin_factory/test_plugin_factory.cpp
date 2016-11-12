//
// Created by Jonathan Picques on 30/10/2016.
//

#include <gtest/gtest.h>

#include <memory>

#include <dude/plugin/manager.hpp>
#include <dude/plugin/behavior.hpp>
#include <dude/plugin/factory.hpp>

class manage : public dude::manager {};
class behave : public dude::behavior {};

TEST(Factory, RegisterPluginsFromType) {
    dude::plugin_factory factory;
    factory.register_manager<manage>("manage");
    factory.register_behavior<behave>("behave");
    auto manage_impl = std::unique_ptr<dude::manager>(factory.make_manager("manage"));
    auto behave_impl = std::unique_ptr<dude::behavior>(factory.make_behavior("behave"));
    EXPECT_EQ(manage_impl->get_name(), "manage");
    EXPECT_EQ(behave_impl->get_name(), "behave");
    #if defined(EXPECT_DEATH_TESTS)
        EXPECT_DEATH_IF_SUPPORTED(factory.make_manager("behave"), "");
        EXPECT_DEATH_IF_SUPPORTED(factory.make_behavior("manage"), "");
    #endif
}

#if defined(DUDE_EMBED_PLUGINS)
TEST(Factory, RegisterPluginsFromEmbeddedType) {
    dude::plugin_factory factory;
    auto manager = std::unique_ptr<dude::manager>(factory.make_manager("input"));
    auto behavior = std::unique_ptr<dude::behavior>(factory.make_behavior("projectile"));
    EXPECT_EQ(manager->get_name(), "input");
    EXPECT_EQ(behavior->get_name(), "projectile");
}
#else
TEST(Factory, RegisterPluginsFromSharedLibrary) {
    dude::plugin_factory factory;
    factory.register_manager("input", "plugins/managers/input/libmanager_input");
    factory.register_behavior("projectile", "plugins/behaviors/projectile/libbehavior_projectile");
    auto manager = std::unique_ptr<dude::manager>(factory.make_manager("input"));
    auto behavior = std::unique_ptr<dude::behavior>(factory.make_behavior("projectile"));
    manager->configure_properties();
    behavior->configure_properties();
    EXPECT_EQ(manager->get_name(), "input");
    EXPECT_EQ(behavior->get_name(), "projectile");
    EXPECT_EQ(behavior->get_property("speed").get<int>(), 10);
    #if defined(EXPECT_DEATH_TESTS)
        EXPECT_DEATH_IF_SUPPORTED(factory.register_behavior("input", "plugins/managers/input/libmanager_input"), "");
        EXPECT_DEATH_IF_SUPPORTED(factory.register_manager("projectile", "plugins/behaviors/projectile/libbehavior_projectile"), "");
    #endif
}
#endif