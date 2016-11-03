//
// Created by Jonathan Picques on 30/10/2016.
//

#include <gtest/gtest.h>

#include <memory>

#include <dude/core/library.hpp>
#include <dude/plugin/behavior.hpp>

TEST(Engine, Library) {
    auto library = dude::library("plugins/managers/input/libmanager_input");
    auto behavior_creator = library.symbol<dude::behavior *(*)()>("create");
    auto behavior = std::unique_ptr<dude::behavior>(behavior_creator());
    EXPECT_TRUE(behavior->name().empty());
    EXPECT_DEATH_IF_SUPPORTED(library.symbol<int (*)()>("undefined_symbol"), "");
}