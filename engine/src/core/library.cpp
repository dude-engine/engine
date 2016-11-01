//
// Created by Jonathan Picques on 01/11/2016.
//

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
            _library = dlopen(library_path.c_str(), RTLD_LOCAL | RTLD_LAZY);
        #endif
    }

    library::~library() {
        #ifdef DUDE_PLATFORM_WINDOWS
            FreeLibrary(reinterpret_cast<HMODULE>(_library));
        #else
            dlclose(_library);
        #endif
    }

    auto library::_symbol(std::string const &symbol) const -> void * {
        #ifdef DUDE_PLATFORM_WINDOWS
            return reinterpret_cast<void *>(GetProcAddress(reinterpret_cast<HMODULE>(_library), symbol.c_str()));
        #else
            return reinterpret_cast<void *>(dlsym(library, symbol.c_str()));
        #endif
    }

}