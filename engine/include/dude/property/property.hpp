//
// Created by Jonathan Picques on 04/11/2016.
//

#pragma once

#include <type_traits>
#include <typeinfo>
#include <utility>
#include <cstddef>
#include <string>
#include <tuple>

namespace dude {

    namespace impl {

        class property_base {
        public:
            property_base() = default;
            virtual ~property_base() noexcept = default;

        public:
            virtual auto is(std::type_info const &type_info) const -> bool = 0;
            virtual auto copy() const -> property_base * = 0;
        };

        template<typename T>
        class property_data : public impl::property_base, std::tuple<T> {
        public:
            template<typename ...Args>
            property_data(Args &&...args) : std::tuple<T>(std::forward<Args>(args)...) {
                static_assert(std::is_same<T, int>::value ||
                              std::is_same<T, float>::value ||
                              std::is_same<T, double>::value ||
                              std::is_same<T, std::string>::value,
                              "properties can only be of type int, float, double or string");
            };
            ~property_data() noexcept = default;

        public:
            auto get() -> T &;
            auto get() const -> T const &;

        public:
            auto is(std::type_info const &type_info) const -> bool override final;
            auto copy() const -> property_base * override final;
        };

    }

}

namespace dude {

    class property {
    public:
        template<typename T> using none_t = typename std::enable_if<!std::is_same<property, T>::value>::type;
        template<typename T> using decay_t = typename std::decay<T>::type;
        using base_t = dude::impl::property_base *;

    public:
        template<typename T, typename U = decay_t<T>, typename = none_t<U>> property(T &&t);

    public:
        property() = default;
        property(property const &p);
        property(property &&p) noexcept;
        ~property() noexcept;

    public:
        auto operator=(property &p) -> property &; // NOLINT
        auto operator=(property &&) noexcept -> property & = delete;

    public:
        template<typename T> auto is() const -> bool;

    public:
        template<typename T> auto get() & -> T &;
        template<typename T> auto get() && -> T &&;
        template<typename T> auto get() const & -> T const &;

    public:
        template<typename T, typename U = decay_t<T>> auto set(T &&t) -> void;
        template<typename T> auto operator=(T &&t) -> void;

    public:
        auto clear() -> void;
        auto empty() const -> bool;

    public:
        friend auto swap(property &a, property &b) -> void;

    private:
        template<typename T> auto safe_get() -> T &;
        template<typename T> auto safe_get() const -> T const &;

    private:
        base_t _base;
    };

}

namespace dude {

    namespace impl {

        template<typename T>
        auto property_data<T>::get() -> T & {
            return std::get<0>(*this);
        }

        template<typename T>
        auto property_data<T>::get() const -> T const & {
            return std::get<0>(*this);
        }

        template<typename T>
        auto property_data<T>::is(std::type_info const &type_info) const -> bool {
            return type_info.name() == typeid(T).name();
        }

        template<typename T>
        auto property_data<T>::copy() const -> property_base * {
            return new property_data{get()};
        }

    }

}

namespace dude {

    template<typename T, typename U, typename>
    property::property(T &&t) : _base{new dude::impl::property_data<U>{std::forward<T>(t)}} {

    }

    template<typename T>
    auto property::is() const -> bool {
        return _base != nullptr && _base->is(typeid(T));
    }

    template<typename T>
    auto property::get() & -> T & {
        return safe_get<T>();
    }

    template<typename T>
    auto property::get() && -> T && {
        return std::move(safe_get<T>());
    }

    template<typename T>
    auto property::get() const & -> T const & {
        return safe_get<T>();
    }

    template<typename T, typename U>
    auto property::set(T &&t) -> void {
        clear();
        _base = new dude::impl::property_data<U>{std::forward<T>(t)};
    }

    template<typename T>
    auto property::operator=(T &&t) -> void {
        set(std::forward<T>(t));
    }

    template<typename T>
    auto property::safe_get() -> T & {
        return dynamic_cast<impl::property_data<T> &>(*_base).get();
    }

    template<typename T>
    auto property::safe_get() const  -> T const & {
        return dynamic_cast<impl::property_data<T> const &>(*_base).get();
    }

}