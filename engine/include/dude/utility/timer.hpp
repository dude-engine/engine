//
// Created by Jonathan Picques on 11/11/2016.
//

#pragma once

#include <chrono>

namespace dude {

    class timer final {
    public:
        using chrono_clock_t = std::chrono::high_resolution_clock;
        using time_point_t = chrono_clock_t::time_point;
        using duration_t = chrono_clock_t::duration;
        using second_t = float;

    public:
        static constexpr second_t fps_update_threshold = 0.2;

    public:
        timer() = default;
        ~timer() = default;

    public:
        timer(timer const &) = delete;
        timer(timer &&) = delete;
        auto operator=(timer const &) -> timer & = delete;

    public:
        auto tick() -> void;

    public:
        auto elapsed() const -> second_t;
        auto frames() const -> second_t;
        auto fps() const -> second_t;
        auto dt() const -> second_t;

    private:
        time_point_t _start;
        time_point_t _previous;
        second_t _frames_threshold = 0;
        second_t _elapsed = 0;
        second_t _frames = 0;
        second_t _fps = 0;
        second_t _dt = 0;
        bool _started = false;
    };

}