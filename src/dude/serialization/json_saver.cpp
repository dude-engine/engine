//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/serialization/json_saver.hpp>

namespace dude {

    auto json_saver::save(const engine &value) const -> std::string {
        buffer buffer;
        writer writer(buffer);

        writer.StartObject();
        writer.Key("type");
        writer.String("engine");
        writer.EndObject();
        return std::string(buffer.GetString());
    }

    auto json_saver::save(const scene &value, writer &writer, buffer &buffer) const -> void {
        writer.StartObject();
        writer.Key("type");
        writer.String("scene");
        writer.EndObject();
    }

    auto json_saver::save(const dude::entity &value, writer &writer, buffer &buffer) const -> void {
        writer.StartObject();
        writer.Key("type");
        writer.String("entity");
        writer.EndObject();
    }

    auto json_saver::save(const dude::behavior &value, writer &writer, buffer &buffer) const -> void {
        writer.StartObject();
        writer.Key("type");
        writer.String("behavior");
        writer.EndObject();
    }

}