//
// Created by Jonathan Picques on 03/11/2016.
//

#include <dude/plugin/plugin.hpp>

namespace dude {

    plugin::~plugin() noexcept { // NOLINT

    }

    auto plugin::on_dependencies() const -> plugin::dependencies_t {
        return dude::plugin::dependencies_t();
    }

    auto plugin::on_properties() const -> plugin::properties_t {
        return dude::plugin::properties_t();
    }

}