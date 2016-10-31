//
// Created by Jonathan Picques on 30/10/2016.
//

#include <gtest/gtest.h>

#include <dude/core/engine.hpp>
#include <dude/serialization/json_saver.hpp>

TEST(Serialization, Basic) {
    dude::engine engine;
    dude::json_saver saver;

    std::cout << saver.save(engine) << std::endl;
}