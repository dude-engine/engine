//
// Created by Jonathan Picques on 12/11/2016.
//

#pragma once

#include <string>
#include <algorithm>

namespace dude {

    template<typename T> auto find_by_name(T const &container, std::string const &name) -> typename T::const_iterator;

}

namespace dude {

    template<typename T>
    auto find_by_name(T const &container, std::string const &name) -> typename T::const_iterator {
        return std::find_if(container.begin(), container.end(), [&name](typename T::value_type const &content) -> bool {
            return content->get_name() == name;
        });
    }

}