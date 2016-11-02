//
// Created by Jonathan Picques on 01/11/2016.
//

#include <cassert>

#include <dude/system.hpp>
#include <dude/core/library.hpp>

#ifdef DUDE_PLATFORM_WINDOWS
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif

namespace dude {

    library::library(std::string const &library_path) {
        #ifdef DUDE_PLATFORM_WINDOWS
            _library = LoadLibrary(library_path.c_str());
        #else
            _library = dlopen((library_path + ".so").c_str(), RTLD_LOCAL | RTLD_LAZY);
        #endif
        assert(_library != nullptr);
    }

    library::~library() {
        #ifdef DUDE_PLATFORM_WINDOWS
            FreeLibrary(reinterpret_cast<HMODULE>(_library));
        #else
            dlclose(_library);
        #endif
    }

    auto library::_symbol(std::string const &symbol) const -> void * {
        auto void_symbol = static_cast<void *>(nullptr);
        #ifdef DUDE_PLATFORM_WINDOWS
            void_symbol = reinterpret_cast<void *>(GetProcAddress(reinterpret_cast<HMODULE>(_library), symbol.c_str()));
        #else
            void_symbol = reinterpret_cast<void *>(dlsym(_library, symbol.c_str()));
        #endif
        assert(void_symbol != nullptr);
        return void_symbol;
    }

}