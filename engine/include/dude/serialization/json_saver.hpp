//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <string>

#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include <dude/core/engine.hpp>
#include <dude/core/scene.hpp>
#include <dude/plugin/manager.hpp>
#include <dude/entity/entity.hpp>
#include <dude/plugin/behavior.hpp>

namespace dude {

    class json_saver final {
    public:
        using buffer_t = rapidjson::StringBuffer;
        using writer_t = rapidjson::Writer<buffer_t>;

    public:
        json_saver() = default;
        ~json_saver() = default;

    private:
        json_saver(json_saver const &) = delete;
        json_saver(json_saver &&) = delete;
        void operator=(json_saver const &) = delete;

    public:
        auto save(engine const &value) const -> std::string;

    public:
        auto save(scene const &value, writer_t &writer, buffer_t &buffer) const -> void;
        auto save(manager const &value, writer_t &writer, buffer_t &buffer) const -> void;
        auto save(entity const &value, writer_t &writer, buffer_t &buffer) const -> void;
        auto save(behavior const &value, writer_t &writer, buffer_t &buffer) const -> void;
    };

}