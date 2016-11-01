//
// Created by Jonathan Picques on 31/10/2016.
//

#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define DUDE_PLATFORM_WINDOWS
#elif defined(linux) || defined(__linux) || defined(__linux__)
    #define DUDE_PLATFORM_LINUX
#elif defined(__APPLE__)
    #define DUDE_PLATFORM_OSX
#elif defined(__EMSCRIPTEN__)
    #define DUDE_PLATFORM_HTML5
#else
    #error Platform not recognized!
#endif

#if defined(DUDE_PLATFORM_WINDOWS)
    #define DUDE_EXPORT __declspec(dllexport)
    #define DUDE_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
    #define DUDE_EXPORT __attribute__((visibility("default")))
    #define DUDE_IMPORT
#else
    #define DUDE_EXPORT
    #define DUDE_IMPORT
#endif

#define DUDE_API DUDE_EXPORT