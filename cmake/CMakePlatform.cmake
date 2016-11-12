if (${MINGW} AND ${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
    # clang++ on Windows complains about nanosleep being not linked
    find_package(Threads)
    target_link_libraries(${DUDE_ENGINE_TARGET} ${CMAKE_THREAD_LIBS_INIT})
endif ()