//
// Created by Jonathan Picques on 04/11/2016.
//

#include <dude/property/property.hpp>

namespace dude {

    namespace impl {

        property_base::property_base() {

        }

        property_base::~property_base() {

        }

    }

}

namespace dude {

    property::property() {

    }

    property::property(property const &p) : _base(p._base->copy()) {

    }

    property::property(property &&p) : _base{p._base} {
        p._base = nullptr;
    }

    property::~property() {
        delete _base;
    }

    auto property::operator=(property &p) -> property & {
        std::swap(_base, p._base);
        return *this;
    }

    auto property::clear() -> void {
        delete _base;
        _base = nullptr;
    }

    auto property::empty() const -> bool {
        return _base == nullptr;
    }

    auto swap(property &a, property &b) -> void {
        std::swap(a._base, b._base);
    }

}