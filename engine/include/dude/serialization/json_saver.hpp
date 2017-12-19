//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <string>

#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>

#include <dude/core/engine.hpp>
#include <dude/core/scene.hpp>
#include <dude/plugin/manager.hpp>
#include <dude/entity/entity.hpp>
#include <dude/plugin/behavior.hpp>
#include <dude/property/property.hpp>

namespace dude {

    class json_saver final {
    public:
        using buffer_t = rapidjson::StringBuffer;
        using writer_t = rapidjson::PrettyWriter<buffer_t>;

    public:
        json_saver() = default;
        ~json_saver() noexcept = default;

    public:
        json_saver(json_saver const &) = delete;
        json_saver(json_saver &&) = delete;
        auto operator=(json_saver const &) -> json_saver & = delete;
        auto operator=(json_saver &&) noexcept -> json_saver & = delete;

    public:
        auto save(dude::engine const &value) const -> std::string;

    public:
        auto save(dude::scene const &value, writer_t &writer, buffer_t &buffer) const -> void;
        auto save(dude::manager const &value, writer_t &writer, buffer_t &buffer) const -> void;
        auto save(dude::entity const &value, writer_t &writer, buffer_t &buffer) const -> void;
        auto save(dude::behavior const &value, writer_t &writer, buffer_t &buffer) const -> void;
        auto save(dude::property const &value, writer_t &writer, buffer_t &buffer) const -> void;
    };

}