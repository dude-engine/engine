//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/serialization/json_saver.hpp>

namespace dude {

    auto json_saver::save(const engine &value) const -> std::string {
        buffer_t buffer;
        writer_t writer(buffer);

        writer.StartObject();
        writer.Key("type");
        writer.String("engine");
        for (auto const &manager : value.managers()) {
            save(*manager.get(), writer, buffer);
        }
        writer.EndObject();
        return std::string(buffer.GetString());
    }

    auto json_saver::save(scene const &value, writer_t &writer, buffer_t &buffer) const -> void {
        writer.StartObject();
        writer.Key("type");
        writer.String("scene");
        for (auto const &entity : value.entities()) {
            save(*entity.get(), writer, buffer);
        }
        writer.EndObject();
    }

    void json_saver::save(const manager &value, writer_t &writer, buffer_t &buffer) const {
        writer.StartObject();
        writer.Key("type");
        writer.String("manager");
        writer.EndObject();
    }

    auto json_saver::save(const entity &value, writer_t &writer, buffer_t &buffer) const -> void {
        writer.StartObject();
        writer.Key("type");
        writer.String("entity");
        for (auto const &entity : value.entities()) {
            save(*entity.get(), writer, buffer);
        }
        for (auto const &behavior : value.behaviors()) {
            save(*behavior.get(), writer, buffer);
        }
        writer.EndObject();
    }

    auto json_saver::save(const behavior &value, writer_t &writer, buffer_t &buffer) const -> void {
        writer.StartObject();
        writer.Key("type");
        writer.String("behavior");
        writer.EndObject();
    }

}