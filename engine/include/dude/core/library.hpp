//
// Created by Jonathan Picques on 01/11/2016.
//

#pragma once

#include <string>

namespace dude {

    class library final {
    public:
        using library_t = void *;

    public:
        library(std::string const &);
        ~library();

    public:
        template<typename T> auto symbol(std::string const &) const -> T;

    private:
        auto _symbol(std::string const &) const -> void *;

    private:
        library_t _library;
    };

}

namespace dude {

    template<typename T>
    auto library::symbol(std::string const &symbol) const -> T {
        return *reinterpret_cast<T>(_symbol(symbol));
    }

}