cmake_minimum_required(VERSION 3.20)
project(course3 C)

set(CMAKE_C_STANDARD 99)

set(SDL2_DIR
        SDL2/SDL2-2.0.22/x86_64-w64-mingw32/include/SDL2
        SDL2/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2
        SDL2/SDL2_ttf-2.0.18/x86_64-w64-mingw32/include/SDL2
        )

set(SDL2_LINK
        SDL2/SDL2-2.0.22/x86_64-w64-mingw32/bin
        SDL2/SDL2_image-2.0.5/x86_64-w64-mingw32/bin
        SDL2/SDL2_ttf-2.0.18/x86_64-w64-mingw32/bin
        )


include_directories(${SDL2_DIR})

link_directories(${SDL2_LINK})

add_executable(course3 main.c
        main.h
        initial.c
        initial.h
        arithmetic.c
        arithmetic.h
        store.c
        store.h
        gamedata.h
        )
ADD_SUBDIRECTORY(begintest)
target_link_libraries(course3 mingw32 SDL2main SDL2 SDL2_image SDL2_ttf)
