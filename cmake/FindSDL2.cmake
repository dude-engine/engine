#############################################
# Try to find SDL2 and set the following:   #
#                                           #
# SDL2_FOUND                                #
# SDL2_INCLUDE_DIR                          #
# SDL2_LIBRARY                              #
#############################################

set(SDL2_PATH "A:\\Programmes\\msys2\\mingw64\\bin" CACHE PATH "The location of SDL2")
set(SDL2_SEARCH_PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /opt
        ${SDL2_PATH}
        )

find_path(SDL2_INCLUDE_DIR SDL.h
        HINTS
        $ENV{SDL2_INCLUDE_DIR}
        PATH_SUFFIXES include/SDL2 include
        PATHS ${SDL2_SEARCH_PATHS}
        )

find_library(SDL2_LIBRARY
        NAMES
        SDL SDL2 SDL2main
        PATHS ${SDL2_SEARCH_PATHS}
        PATH_SUFFIXES lib64 lib lib/x86 lib/x64
        $ENV{SDL2_LIBRARY}
        )

if (SDL2_INCLUDE_DIR AND SDL2_LIBRARY)
    set(SDL2_FOUND TRUE)
else (SDL2_INCLUDE_DIR AND SDL2_LIBRARY)
    set(SDL2_FOUND FALSE)
endif (SDL2_INCLUDE_DIR AND SDL2_LIBRARY)