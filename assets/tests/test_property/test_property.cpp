//
// Created by Jonathan Picques on 30/10/2016.
//

#include <gtest/gtest.h>

#include <cstddef>
#include <vector>
#include <string>

#include <dude/property/property.hpp>

TEST(Property, Basic) {
    dude::property p1 = std::string{"hello"};
    dude::property p2 = 32;
    dude::property p3 = p2;
    dude::property p4{p3};
    dude::property p5 = std::string{"empty"};
    auto p6 = std::move(p5);

    EXPECT_TRUE(p1.is<std::string>());
    EXPECT_EQ(p1.get<std::string>(), "hello");
    EXPECT_TRUE(p2.is<int>());
    EXPECT_EQ(p2.get<int>(), 32);
    EXPECT_TRUE(p2.is<int>());
    EXPECT_EQ(p3.get<int>(), 32);
    EXPECT_TRUE(p2.is<int>());
    EXPECT_EQ(p4.get<int>(), 32);
    EXPECT_FALSE(p5.is<std::string>()); // NOLINT: p5 used after move
    EXPECT_TRUE(p5.empty()); // NOLINT: p5 used after move
    EXPECT_TRUE(p6.is<std::string>());
    EXPECT_EQ(p6.get<std::string>(), "empty");

    p3 = 3.0f;

    EXPECT_TRUE(p3.is<float>());
    EXPECT_EQ(p3.get<float>(), 3.0f);

    std::vector<dude::property> properties({32, std::string{"hello"}, p3, 78.f});

    EXPECT_EQ(properties.at(0).get<int>(), 32);
    EXPECT_EQ(properties.at(1).get<std::string>(), "hello");
    EXPECT_EQ(properties.at(2).get<float>(), p3.get<float>());
    EXPECT_EQ(properties.at(3).get<float>(), 78.f);

    properties.at(3) = 78;

    EXPECT_EQ(properties.at(3).get<int>(), 78);

    properties.at(3).clear();

    EXPECT_FALSE(properties.at(3).is<int>());
    EXPECT_TRUE(properties.at(3).empty());
}