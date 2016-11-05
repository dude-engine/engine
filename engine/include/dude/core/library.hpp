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
        library(std::string const &path);
        ~library();

    private:
        library(library const &) = delete;
        library(library &&) = delete;
        void operator=(library const &) = delete;

    public:
        template<typename T> auto symbol(std::string const &symbol_name) const -> T;

    private:
        auto _symbol(std::string const &symbol_name) const -> void *;

    private:
        library_t _library;
    };

}

namespace dude {

    template<typename T>
    auto library::symbol(std::string const &symbol_name) const -> T {
        return *reinterpret_cast<T>(_symbol(symbol_name));
    }

}