//
// Created by Jonathan Picques on 30/10/2016.
//

#include <gtest/gtest.h>

#include <dude/plugin/manager.hpp>
#include <dude/plugin/behavior.hpp>
#include <dude/plugin/factory.hpp>

class manage : public dude::manager {};
class behave : public dude::behavior {};

TEST(Factory, RegisterPluginsFromType) {
    dude::plugin_factory factory;
    factory.register_manager<manage>("manage");
    factory.register_behavior<behave>("behave");
    auto manage_impl = factory.make_manager("manage");
    auto behave_impl = factory.make_behavior("behave");
    EXPECT_EQ(manage_impl->name(), "manage");
    EXPECT_EQ(behave_impl->name(), "behave");

    EXPECT_DEATH_IF_SUPPORTED(factory.make_manager("behave"), "");
    EXPECT_DEATH_IF_SUPPORTED(factory.make_behavior("manage"), "");
}

#if defined(DUDE_EMBED_PLUGINS)
    TEST(Factory, InputPluginsRegisteredWhenEmbeddingPlugins) {
        dude::plugin_factory factory;
        auto manager = factory.make_manager("input");
        auto behavior = factory.make_behavior("bullet");
        EXPECT_EQ(manager->name(), "input");
        EXPECT_EQ(behavior->name(), "bullet");
    }
#else
    TEST(Factory, RegisterPluginsFromSharedLibrary) {
        dude::plugin_factory factory;
        factory.register_manager("input", "plugins/managers/input/libmanager_input");
        factory.register_behavior("bullet", "plugins/behaviors/bullet/libbehavior_bullet");
        auto manager = factory.make_manager("input");
        auto behavior = factory.make_behavior("bullet");
        EXPECT_EQ(manager->name(), "input");
        EXPECT_EQ(behavior->name(), "bullet");

        EXPECT_DEATH_IF_SUPPORTED(factory.register_behavior("input", "plugins/managers/input/libmanager_input"), "");
        EXPECT_DEATH_IF_SUPPORTED(factory.register_manager("bullet", "plugins/behaviors/bullet/libbehavior_bullet"), "");
    }
#endif