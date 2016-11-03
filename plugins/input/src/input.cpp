//
// Created by Jonathan Picques on 01/11/2016.
//

#include <input/input.hpp>

extern "C" {
    DUDE_API dude::behavior *create();
    DUDE_API dude::behavior *create() {
        return new dude::input();
    }
}