//
// Created by Jonathan Picques on 01/11/2016.
//

#include <cassert>

#include <dude/system.hpp>
#include <dude/utility/library.hpp>

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
        #if defined(DUDE_PLATFORM_HTML5) && defined(DUDE_EMBED_PLUGINS)
            assert(false && "The HTML5 engine has been built without dynamic loading to improve performances");
        #endif
        #if defined(DUDE_PLATFORM_WINDOWS)
            _library = LoadLibrary((path + LIBRARY_EXT).c_str());
        #else
            _library = dlopen((path + LIBRARY_EXT).c_str(), RTLD_NOW);
        #endif
        assert(_library != nullptr);
    }

    library::~library() {
        #if defined(DUDE_PLATFORM_WINDOWS)
            assert(FreeLibrary(reinterpret_cast<HMODULE>(_library)));
        #else
            assert(dlclose(_library) == 0);
        #endif
    }

    auto library::_get_symbol(std::string const &symbol_name) const -> void * {
        void *symbol = nullptr;
        #if defined(DUDE_PLATFORM_WINDOWS)
            symbol = reinterpret_cast<void *>(GetProcAddress(reinterpret_cast<HMODULE>(_library), symbol_name.c_str()));
        #else
            symbol = reinterpret_cast<void *>(dlsym(_library, symbol_name.c_str()));
        #endif
        assert(symbol != nullptr);
        return symbol;
    }

}