//
// Created by Jonathan Picques on 01/11/2016.
//

#include <cassert>

#include <dude/system.hpp>
#include <dude/core/library.hpp>

#if defined(DUDE_PLATFORM_WINDOWS)
    #include <windows.h>
    #define LIBRARY_EXT ".dll"
#else
    #include <dlfcn.h>
    #if defined(DUDE_PLATFORM_LINUX)
        #define LIBRARY_EXT ".so"
    #elif defined(DUDE_PLATFORM_OSX)
        #define LIBRARY_EXT ".dylib"
    #elif defined(DUDE_PLATFORM_HTML5)
        #define LIBRARY_EXT ".js"
    #endif
#endif

namespace dude {

    library::library(std::string const &path) {
        #if defined(DUDE_PLATFORM_WINDOWS)
            _library = LoadLibrary((path + LIBRARY_EXT).c_str());
        #else
            _library = dlopen((path + LIBRARY_EXT).c_str(), RTLD_NOW);
        #endif
        assert(_library != nullptr);
    }

    library::~library() {
        #if defined(DUDE_PLATFORM_WINDOWS)
            FreeLibrary(reinterpret_cast<HMODULE>(_library));
        #else
            dlclose(_library);
        #endif
    }

    auto library::_symbol(std::string const &symbol_name) const -> void * {
        auto void_symbol = static_cast<void *>(nullptr);
        #if defined(DUDE_PLATFORM_WINDOWS)
            void_symbol = reinterpret_cast<void *>(GetProcAddress(reinterpret_cast<HMODULE>(_library), symbol_name.c_str()));
        #else
            void_symbol = reinterpret_cast<void *>(dlsym(_library, symbol_name.c_str()));
        #endif
        assert(void_symbol != nullptr);
        return void_symbol;
    }

}