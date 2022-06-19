    cmake_minimum_required(VERSION 3.20)
    project(begintest)

    set(CMAKE_C_STANDARD 99)

    include_directories(SDL)

    add_executable(begintest begintest.c ../arithmetic.c ../arithmetic.h ../initial.h ../initial.c ../store.c ../store.h)

    target_link_libraries(begintest mingw32 SDL2main SDL2 SDL2_image SDL2_ttf CUnit)
