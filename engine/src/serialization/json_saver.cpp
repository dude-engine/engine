//
// Created by Jonathan Picques on 31/10/2016.
//

#include <dude/serialization/json_saver.hpp>

namespace dude {

    auto json_saver::save(engine const &value) const -> std::string {
        buffer_t buffer;
        writer_t writer(buffer);

        writer.StartObject();
        writer.Key("type");
        writer.String("engine");
        for (auto const &manager : value.get_managers()) {
            save(*manager.get(), writer, buffer);
        }
        writer.EndObject();
        return std::string(buffer.GetString());
    }

    auto json_saver::save(scene const &value, writer_t &writer, buffer_t &buffer) const -> void {
        writer.StartObject();
        writer.Key("type");
        writer.String("scene");
        for (auto const &entity : value.get_entities()) {
            save(*entity.get(), writer, buffer);
        }
        writer.EndObject();
    }

    auto json_saver::save(entity const &value, writer_t &writer, buffer_t &buffer) const -> void {
        writer.StartObject();
        writer.Key("type");
        writer.String("entity");
        for (auto const &child : value.get_children()) {
            save(*child.get(), writer, buffer);
        }
        for (auto const &behavior : value.get_behaviors()) {
            save(*behavior.get(), writer, buffer);
        }
        writer.EndObject();
    }

    void json_saver::save(manager const &value, writer_t &writer, buffer_t &buffer) const {
        writer.StartObject();
        writer.Key("type");
        writer.String("manager");
        writer.Key("properties");
        writer.StartObject();
        for (const auto &property: value.get_properties()) {
            writer.String(property.first.c_str());
            save(property.second, writer, buffer);
        }
        writer.EndObject();
        writer.EndObject();
    }

    auto json_saver::save(behavior const &value, writer_t &writer, buffer_t &buffer) const -> void {
        writer.StartObject();
        writer.Key("type");
        writer.String("behavior");
        writer.Key("properties");
        writer.StartObject();
        for (const auto &property: value.get_properties()) {
            writer.String(property.first.c_str());
            save(property.second, writer, buffer);
        }
        writer.EndObject();
        writer.EndObject();
    }

    auto json_saver::save(property const &value, writer_t &writer, buffer_t &buffer) const -> void {
        if (value.is<int>()) {
            writer.Int(value.get<int>());
        } else if (value.is<float>()) {
            writer.Double(value.get<float>());
        } else if (value.is<double>()) {
            writer.Double(value.get<double>());
        } else if (value.is<std::string>()) {
            writer.String(value.get<std::string>().c_str());
        } else {
            writer.Null();
        }
    }

}