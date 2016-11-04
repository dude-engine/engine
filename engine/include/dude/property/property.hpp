//
// Created by Jonathan Picques on 04/11/2016.
//

#pragma once

#include <utility>

#if __has_include(<any>)
    #include <any>
    #define ANY_IMPL std::any
    #define ANY_CAST_IMPL std::any_cast
#else
    #include <experimental/any>
    #define ANY_IMPL std::experimental::any
    #define ANY_CAST_IMPL std::experimental::any_cast
#endif

namespace dude {

    using property = ANY_IMPL;

    template<typename T, typename ...Args>
    auto property_cast(Args &&... args) -> decltype(ANY_CAST_IMPL<T>(std::forward<Args>(args)...));

    template<typename T>
    auto property_is(property const &p) -> bool;

}

namespace dude {

    template<typename T, typename ...Args>
    auto property_cast(Args &&... args) -> decltype(ANY_CAST_IMPL<T>(std::forward<Args>(args)...)) {
        return ANY_CAST_IMPL<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    auto property_is(property const &p) -> bool {
        return !p.empty() && p.type() == typeid(T);
    }

}