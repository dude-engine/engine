//
// Created by Jonathan Picques on 04/11/2016.
//

#pragma once

#include <type_traits>
#include <typeinfo>
#include <cstddef>
#include <tuple>

namespace dude {

    namespace impl {

        class property_base {
        public:
            property_base();
            virtual ~property_base();

        public:
            virtual auto is(std::type_info const &type_info) const -> bool = 0;
            virtual auto copy() const -> property_base * = 0;
        };

        template<typename T>
        class property_data : public property_base, public std::tuple<T> {
        public:
            using std::tuple<T>::tuple;

        public:
            auto get() -> T & { return std::get<0>(*this); }
            auto get() const -> T const & { return std::get<0>(*this); }

        public:
            auto is(std::type_info const &type_info) const -> bool override final { return type_info.name() == typeid(T).name(); }
            auto copy() const -> property_base * override final { return new property_data{get()}; }
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
        template<typename T, typename U = decay_t<T>, typename = none_t<U>> property(T &&t) : _base{new dude::impl::property_data<U>{std::forward<T>(t)}} {}

    public:
        property();
        property(property const &p);
        property(property &&p);
        ~property();

    public:
		property &operator=(property &p);

    public:
        template<typename T> auto is() const -> bool { return _base != nullptr && _base->is(typeid(T)); }

    public:
        template<typename T> auto get() & -> T & { return safe_get<T>(); };
        template<typename T> auto get() && -> T && { return std::move(safe_get<T>()); };
        template<typename T> auto get() const & -> T const & { return safe_get<T>(); };

    public:
        template<typename T, typename U = decay_t<T>> auto set(T &&t) -> void { clear(); _base = new dude::impl::property_data<U>{std::forward<T>(t)}; }
        template<typename T> auto operator=(T &&t) -> void { set(std::forward<T>(t)); };

    public:
        auto clear() -> void;
        auto empty() const -> bool;

    public:
        friend auto swap(property &a, property &b) -> void;

    private:
        template<typename T> auto safe_get() -> T & { return dynamic_cast<dude::impl::property_data<T> &>(*_base).get(); }
        template<typename T> auto safe_get() const  -> T const & { return dynamic_cast<dude::impl::property_data<T> const &>(*_base).get(); }

    private:
        base_t _base;
    };

}