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
        explicit library(std::string const &path);
        ~library();

    public:
        library(library const &) = delete;
        library(library &&) = delete;
        auto operator=(library const &) -> library & = delete;

    public:
        template<typename T> auto get_symbol(std::string const &symbol_name) const -> T;

    private:
        auto _get_symbol(std::string const &symbol_name) const -> void *;

    private:
        library_t _library;
    };

}

namespace dude {

    template<typename T>
    auto library::get_symbol(std::string const &symbol_name) const -> T {
        return *reinterpret_cast<T>(_get_symbol(symbol_name));
    }

}