//
// Created by Jonathan Picques on 03/11/2016.
//

#pragma once

#include <string>
#include <unordered_set>
#include <unordered_map>

#include <dude/system.hpp>
#include <dude/property/property.hpp>

namespace dude {

    class DUDE_API plugin {
    public:
        using dependencies_t = std::unordered_set<std::string>;
        using properties_t = std::unordered_map<std::string, dude::property>;

    public:
        plugin() = default;
        virtual ~plugin() = 0;

    public:
        plugin(plugin const &) = delete;
        plugin(plugin &&) = delete;
        auto operator=(plugin const &) -> plugin & = delete;

    public:
        virtual auto on_dependencies() const -> dependencies_t;
        virtual auto on_properties() const -> properties_t;
    };

}