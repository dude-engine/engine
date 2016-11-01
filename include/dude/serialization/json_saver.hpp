//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#include <string>

#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include <dude/core/engine.hpp>
#include <dude/core/scene.hpp>
#include <dude/entity/entity.hpp>
#include <dude/behavior/behavior.hpp>

namespace dude {

    class json_saver {
    public:
        using buffer_t = rapidjson::StringBuffer;
        using writer_t = rapidjson::Writer<buffer_t>;

    public:
        json_saver() = default;
        ~json_saver() = default;

    public:
        auto save(engine const &value) const -> std::string;
        auto save(scene const &value) const -> std::string;

    public:
        auto save(entity const &value, writer_t &writer, buffer_t &buffer) const -> void;
        auto save(behavior const &value, writer_t &writer, buffer_t &buffer) const -> void;
    };

}