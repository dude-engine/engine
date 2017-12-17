//
// Created by Jonathan Picques on 11/11/2016.
//

#include <dude/utility/timer.hpp>

namespace dude {

    auto timer::tick() -> void {
        if (!_started) {
            _start = chrono_clock_t::now();
            _previous = chrono_clock_t::now();
            _started = true;
        }
        _dt = std::chrono::duration_cast<duration_t>(chrono_clock_t::now() - _previous).count();
        _elapsed = std::chrono::duration_cast<duration_t>(chrono_clock_t::now() - _start).count();
        _previous = chrono_clock_t::now();
        _frames += 1;
        _frames_threshold += _dt;
        if (_frames_threshold > fps_update_threshold) {
            _fps = _frames / _frames_threshold;
            _frames_threshold = 0;
            _frames = 0;
        }
    }

    auto timer::elapsed() const -> timer::second_t {
        return (_elapsed * duration_t::period::num) / duration_t::period::den;
    }

    auto timer::frames() const -> timer::second_t {
        return (_frames * duration_t::period::num) / duration_t::period::den;
    }

    auto timer::fps() const -> timer::second_t {
        return (_fps * duration_t::period::num) / duration_t::period::den;
    }

    auto timer::dt() const -> timer::second_t {
        return (_dt * duration_t::period::num) / duration_t::period::den;
    }

}