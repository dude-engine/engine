//
// Created by Jonathan Picques on 31/10/2016.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <SDL2/SDL.h>

#include <dude/core/timer.hpp>

int main() {
    dude::timer timer;
    dude::timer::second_t dt;
    dude::timer::second_t acc_update = 0;
    dude::timer::second_t acc_update_frames = 0;
    dude::timer::second_t acc_render = 0;
    dude::timer::second_t acc_render_frames = 0;
    dude::timer::second_t accumulator_total = 0;
    while (true) {
        timer.tick();
        dt = timer.dt();
        acc_update += dt;
        acc_render += dt;
        if (acc_update > 1. / 120.) {
            acc_update_frames += 1;
            acc_update = 0;
        }
        if (acc_render > 1. / 60.) {
            acc_render_frames += 1;
            acc_render = 0;
        }
        accumulator_total += dt;
        if (accumulator_total > 1) {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds{1});
    }
    std::cout << std::endl;
    std::cout << "updated " << acc_update_frames << " times in " << timer.elapsed() << " second(s)" << std::endl;
    std::cout << "rendered " << acc_render_frames << " frames in " << timer.elapsed() << " second(s)" << std::endl;
    return 0;
}